/*
** EPITECH PROJECT, 2025
** My_Hunter
** File description:
** kirby
*/

#include "../include/my.h"

static void init_kirby_sprite(kirby_t *kirby)
{
    kirby->sprite = sfSprite_create();
    sfSprite_setTexture(kirby->sprite, kirby->texture, sfTrue);
    kirby->rect = malloc(sizeof(sfIntRect));
    kirby->rect->top = 0;
    kirby->rect->left = 0;
    kirby->rect->width = 362;
    kirby->rect->height = 366;
    sfSprite_setTextureRect(kirby->sprite, *kirby->rect);
}

kirby_t *generate_kirby(void)
{
    kirby_t *kirby = malloc(sizeof(kirby_t));

    kirby->texture = sfTexture_createFromFile("./content/kirby.png", NULL);
    init_kirby_sprite(kirby);
    kirby->pos.x = 300;
    kirby->pos.y = 300;
    kirby->scale.x = 0.5;
    kirby->scale.y = 0.5;
    kirby->clock = sfClock_create();
    sfSprite_setPosition(kirby->sprite, kirby->pos);
    sfSprite_setScale(kirby->sprite, kirby->scale);
    kirby->speed_x = 0.f;
    kirby->speed_y = 0.8f;
    kirby->direction = 1;
    kirby->movement_pattern = 0;
    kirby->movement_timer = 0.0f;
    kirby->amplitude = 50.0f;
    kirby->frequency = 1.0f;
    return kirby;
}

void change_kirby_sprite(sfClock *clock, sfSprite *kirby_sprite,
    sfIntRect *kirby_rect)
{
    float frame_time = 0.12f;
    float elapsed = sfTime_asSeconds(sfClock_getElapsedTime(clock));

    if (elapsed < frame_time)
        return;
    sfClock_restart(clock);
    if (kirby_rect->left == 730)
        kirby_rect->left = 0;
    else
        kirby_rect->left += 365;
    sfSprite_setTextureRect(kirby_sprite, *kirby_rect);
}
