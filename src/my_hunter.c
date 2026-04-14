/*
** EPITECH PROJECT, 2025
** Graphical_Programming
** File description:
** My Hunter
*/

#include "../include/my.h"

static void init_objects(struct objects_s *obj)
{
    obj->kirby = generate_kirby();
    obj->button = generate_button();
    obj->background = generate_background();
    obj->text = generate_text();
    obj->counter_f = generate_counter();
    obj->crosshair = generate_crosshair();
    obj->bullets = generate_bullets();
    obj->window = create_window();
    init_music(obj);
}

static void handle_esc(sfRenderWindow *win, struct game_state_s *st)
{
    if (st->paused) {
        sfRenderWindow_close(win);
    } else {
        st->paused = true;
        if (st->exit_text == NULL)
            st->exit_text = create_exit_text();
    }
}

static void handle_close_event(sfRenderWindow *win, sfEvent *ev)
{
    if (ev->type == sfEvtClosed)
        sfRenderWindow_close(win);
}

static void handle_escape_key(sfRenderWindow *win, sfEvent *ev,
    struct game_state_s *st)
{
    if (ev->type == sfEvtKeyPressed && ev->key.code == sfKeyEscape)
        handle_esc(win, st);
}

static void handle_start_button(sfEvent *ev, struct game_state_s *st)
{
    if (ev->type == sfEvtMouseButtonReleased && st->button_clicked)
        st->start_counter = true;
}

static void handle_gameplay_click(sfRenderWindow *win, sfEvent *ev,
    struct game_state_s *st, struct objects_s *obj)
{
    int hit;

    if (st->game_started && !st->paused) {
        hit = handle_kirby_click(win, ev, obj->crosshair, obj->bullets);
        process_hit(st, obj, hit);
    }
}

static void do_events(sfRenderWindow *win, sfEvent *ev,
    struct game_state_s *st, struct objects_s *obj)
{
    while (sfRenderWindow_pollEvent(win, ev)) {
        handle_close_event(win, ev);
        handle_escape_key(win, ev, st);
        handle_start_button(ev, st);
        handle_gameplay_click(win, ev, st, obj);
    }
}

static void start_game_after_countdown(struct game_state_s *st,
    struct objects_s *obj)
{
    int countdown_finished = is_counter_finished(obj->counter_f->rect);

    if (st->start_counter && !st->game_started && countdown_finished) {
        st->game_started = true;
        init_game();
    }
}

static void show_game_over_screen(struct game_state_s *st)
{
    if (st->game_started && is_game_over() && st->game_over_text == NULL) {
        st->game_over_text = create_game_over_text(st->score,
            get_miss_count(), get_escape_count());
    }
}

static void switch_to_game_over_music(struct game_state_s *st,
    struct objects_s *obj)
{
    if (st->game_started && is_game_over() && !st->music_changed) {
        sfMusic_stop(obj->music);
        sfMusic_play(obj->game_over_music);
        st->music_changed = true;
    }
}

static void upd_state(struct game_state_s *st, struct objects_s *obj)
{
    start_game_after_countdown(st, obj);
    show_game_over_screen(st);
    switch_to_game_over_music(st, obj);
}

static void upd_kirby(struct game_state_s *st, struct objects_s *obj)
{
    if (st->paused == true)
        return;
    if (st->game_started && is_game_over() == false) {
        spawn_kirbys();
        update_kirbys();
    } else if (st->start_counter == false) {
        update_initial_kirby(obj);
    } else {
        obj->kirby->pos.x -= 1.0f;
        obj->kirby->pos.y -= 1.0f;
    }
}

static void draw_game(sfRenderWindow *win, struct game_state_s *st,
    struct objects_s *obj)
{
    sfRenderWindow_clear(win, sfWhite);
    if (st->game_started == false)
        change_kirby_sprite(obj->kirby->clock, obj->kirby->sprite,
            obj->kirby->rect);
    st->button_clicked = change_button_sprite(win, obj->button,
        st->start_counter);
    change_crosshair_sprite(obj->crosshair, win);
    sfRenderWindow_drawSprite(win, obj->background->sprite, NULL);
    render_game_objects(win, st->game_started, obj);
}

static void draw_ui(sfRenderWindow *win, struct game_state_s *st,
    struct objects_s *obj)
{
    if (st->start_counter == false)
        sfRenderWindow_drawSprite(win, obj->button->sprite, NULL);
    sfRenderWindow_drawText(win, obj->text->text, NULL);
    render_counter_ui(win, st->start_counter, st->game_started, obj);
    if (st->game_over_text != NULL)
        sfRenderWindow_drawText(win, st->game_over_text, NULL);
    if (st->paused == true && st->exit_text != NULL)
        sfRenderWindow_drawText(win, st->exit_text, NULL);
    sfRenderWindow_drawSprite(win, obj->crosshair->sprite, NULL);
    sfRenderWindow_display(win);
}

static void init_state(struct game_state_s *st)
{
    st->button_clicked = false;
    st->start_counter = false;
    st->game_started = false;
    st->score = 0;
    st->game_over_text = NULL;
    st->music_changed = false;
    st->paused = false;
    st->exit_text = NULL;
}

int main(int ac, char **av)
{
    struct objects_s obj;
    struct game_state_s state;
    sfEvent event;

    if (check_args(ac, av))
        return 0;
    init_state(&state);
    init_objects(&obj);
    while (sfRenderWindow_isOpen(obj.window)) {
        do_events(obj.window, &event, &state, &obj);
        upd_state(&state, &obj);
        upd_kirby(&state, &obj);
        if (state.game_started == false)
            sfSprite_setPosition(obj.kirby->sprite, obj.kirby->pos);
        draw_game(obj.window, &state, &obj);
        draw_ui(obj.window, &state, &obj);
    }
    return 0;
}
