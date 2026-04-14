/*
** EPITECH PROJECT, 2025
** Graphical_Programming
** File description:
** My Hunter utilities
*/

#include "../include/my.h"

void render_game_objects(sfRenderWindow *win, bool started,
    struct objects_s *obj)
{
    if (started) {
        draw_kirbys(win);
        draw_bullets(win, obj->bullets);
    } else {
        sfRenderWindow_drawSprite(win, obj->kirby->sprite, NULL);
    }
}

void render_counter_ui(sfRenderWindow *win, bool start_cnt,
    bool started, struct objects_s *obj)
{
    if (start_cnt && !started) {
        counter(obj->counter_f->clock, obj->counter_f->sprite,
            obj->counter_f->rect);
        sfRenderWindow_drawSprite(win, obj->counter_f->sprite, NULL);
    }
}

void update_initial_kirby(struct objects_s *o)
{
    o->kirby->pos.y += o->kirby->speed_y * o->kirby->direction;
    if (o->kirby->pos.y > 300 || o->kirby->pos.y < 200)
        o->kirby->direction *= -1;
}

void process_hit(struct game_state_s *st, struct objects_s *o, int hit)
{
    if (hit) {
        st->score++;
        update_score_text(o->text, st->score);
    }
}

sfText *create_exit_text(void)
{
    sfFont *f = sfFont_createFromFile("./content/font.TTF");
    sfText *txt;
    sfVector2f pos;

    pos.x = 700;
    pos.y = 500;
    if (f == NULL)
        return NULL;
    txt = sfText_create();
    if (txt == NULL)
        return NULL;
    sfText_setFont(txt, f);
    sfText_setString(txt, "PAUSED\n\nPress     ESC     to     exit");
    sfText_setCharacterSize(txt, 60);
    sfText_setFillColor(txt, sfWhite);
    sfText_setPosition(txt, pos);
    return txt;
}
