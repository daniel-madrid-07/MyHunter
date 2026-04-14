/*
** EPITECH PROJECT, 2025
** Graphical_Programming
** File description:
** Game
*/

#include "../include/my.h"

game_data_t *get_game_data(void)
{
    static game_data_t data = {{NULL}, 0, NULL, 1.0f, 0, false, 0};

    return &data;
}

void init_game(void)
{
    int i;

    for (i = 0; i < 10; i++)
        get_game_data()->kirbys[i] = NULL;
    get_game_data()->active_kirbys = 0;
    get_game_data()->speed_multiplier = 1.0f;
    get_game_data()->miss_count = 0;
    get_game_data()->game_over = false;
    get_game_data()->spawn_counter = 0;
    if (get_game_data()->spawn_clock == NULL)
        get_game_data()->spawn_clock = sfClock_create();
    sfClock_restart(get_game_data()->spawn_clock);
}

static void set_move(kirby_t *k)
{
    int position_index = get_game_data()->spawn_counter % 4;
    int heights[] = {200, 400, 600, 300};

    k->pos.y = heights[position_index];
    if (get_game_data()->spawn_counter % 2 == 0)
        set_kirby_left_direction(k);
    else
        set_kirby_right_direction(k);
    get_game_data()->spawn_counter++;
}

static void add_kirby(kirby_t *k)
{
    int i;

    for (i = 0; i < 10; i++) {
        if (get_game_data()->kirbys[i] == NULL) {
            get_game_data()->kirbys[i] = k;
            get_game_data()->active_kirbys++;
            break;
        }
    }
}

static void spawn_kirby(void)
{
    kirby_t *k;

    if (get_game_data()->active_kirbys >= 10)
        return;
    k = generate_kirby();
    set_move(k);
    k->speed_y = 0.0f;
    sfSprite_setPosition(k->sprite, k->pos);
    sfSprite_setTextureRect(k->sprite, *k->rect);
    add_kirby(k);
}

static float get_seconds_since_last_spawn(void)
{
    sfTime elapsed = sfClock_getElapsedTime(get_game_data()->spawn_clock);

    return sfTime_asSeconds(elapsed);
}

void spawn_kirbys(void)
{
    float spawn_interval = 1.5f;
    float seconds_elapsed;

    if (get_game_data()->game_over)
        return;
    seconds_elapsed = get_seconds_since_last_spawn();
    if (seconds_elapsed >= spawn_interval) {
        spawn_kirby();
        sfClock_restart(get_game_data()->spawn_clock);
    }
}

void update_kirbys(void)
{
    int i;

    for (i = 0; i < 10; i++) {
        if (get_game_data()->kirbys[i] != NULL)
            update_single_kirby(i);
    }
}

static int is_valid_click(sfEvent *ev)
{
    if (get_game_data()->game_over)
        return 0;
    if (ev->type != sfEvtMouseButtonPressed)
        return 0;
    if (ev->mouseButton.button != sfMouseLeft)
        return 0;
    return 1;
}

static sfVector2f get_mouse_position(sfRenderWindow *win)
{
    sfVector2i mouse_pos_int = sfMouse_getPositionRenderWindow(win);
    sfVector2f mouse_pos_float;

    mouse_pos_float.x = (float)mouse_pos_int.x;
    mouse_pos_float.y = (float)mouse_pos_int.y;
    return mouse_pos_float;
}

static int try_hit_kirbys(sfVector2f mouse_pos, crosshair_t *cross)
{
    int i;

    for (i = 0; i < 10; i++) {
        if (check_hit(i, mouse_pos, cross))
            return 1;
    }
    return 0;
}

static void handle_miss(bullets_t *bul)
{
    get_game_data()->miss_count++;
    update_bullets_on_miss(bul);
    if (get_game_data()->miss_count >= 3)
        get_game_data()->game_over = true;
}

int handle_kirby_click(sfRenderWindow *win, sfEvent *ev,
    crosshair_t *cross, bullets_t *bul)
{
    sfVector2f mouse_pos;
    int hit_kirby;

    if (is_valid_click(ev) == 0)
        return 0;
    mouse_pos = get_mouse_position(win);
    hit_kirby = try_hit_kirbys(mouse_pos, cross);
    if (hit_kirby == 1)
        return 1;
    handle_miss(bul);
    return 0;
}
