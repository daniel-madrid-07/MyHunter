/*
** EPITECH PROJECT, 2025
** My_Hunter
** File description:
** counter
*/

#include "../include/my.h"

static void init_counter_sprite(counter_t *counter, sfTexture *texture)
{
    counter->sprite = sfSprite_create();
    sfSprite_setTexture(counter->sprite, texture, sfTrue);
    counter->rect = malloc(sizeof(sfIntRect));
    counter->rect->top = 0;
    counter->rect->left = 0;
    counter->rect->width = 150;
    counter->rect->height = 377;
    sfSprite_setTextureRect(counter->sprite, *counter->rect);
}

counter_t *generate_counter(void)
{
    counter_t *counter = malloc(sizeof(counter_t));
    sfTexture *texture;

    texture = sfTexture_createFromFile("./content/counter.png", NULL);
    init_counter_sprite(counter, texture);
    counter->pos.x = 915;
    counter->pos.y = 400;
    counter->scale.x = 1;
    counter->scale.y = 1;
    counter->clock = sfClock_create();
    sfSprite_setPosition(counter->sprite, counter->pos);
    sfSprite_setScale(counter->sprite, counter->scale);
    return counter;
}

void counter(sfClock *clock, sfSprite *counter_sprite,
    sfIntRect *counter_rect)
{
    float frame_time = 1.0f;
    float elapsed = sfTime_asSeconds(sfClock_getElapsedTime(clock));
    static bool counter_started = false;

    if (counter_started != true) {
        counter_started = true;
        sfClock_restart(clock);
        return;
    }
    if (elapsed < frame_time)
        return;
    sfClock_restart(clock);
    counter_rect->left += 180;
    sfSprite_setTextureRect(counter_sprite, *counter_rect);
}
