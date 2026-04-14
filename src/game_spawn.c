/*
** EPITECH PROJECT, 2025
** Graphical_Programming
** File description:
** Game spawn utilities
*/

#include "../include/my.h"

void set_kirby_left_direction(kirby_t *k)
{
    k->pos.x = -200;
    k->speed_x = 1.5f * get_game_data()->speed_multiplier;
    k->direction = 1;
    sfTexture_destroy(k->texture);
    k->texture = sfTexture_createFromFile("./content/kirby.png", NULL);
    sfSprite_setTexture(k->sprite, k->texture, sfTrue);
}

void set_kirby_right_direction(kirby_t *k)
{
    char *path = "./content/kirby_reversed.png";

    k->pos.x = 2100;
    k->speed_x = -1.5f * get_game_data()->speed_multiplier;
    k->direction = -1;
    sfTexture_destroy(k->texture);
    k->texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(k->sprite, k->texture, sfTrue);
}

void remove_kirby(int i)
{
    kirby_t *k = get_game_data()->kirbys[i];

    sfSprite_destroy(k->sprite);
    sfTexture_destroy(k->texture);
    sfClock_destroy(k->clock);
    free(k->rect);
    free(k);
    get_game_data()->kirbys[i] = NULL;
    get_game_data()->active_kirbys--;
}

void update_single_kirby(int i)
{
    kirby_t *k = get_game_data()->kirbys[i];

    k->pos.x += k->speed_x;
    sfSprite_setPosition(k->sprite, k->pos);
    change_kirby_sprite(k->clock, k->sprite, k->rect);
    if (k->pos.x < -300 || k->pos.x > 2200)
        remove_kirby(i);
}
