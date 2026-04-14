/*
** EPITECH PROJECT, 2025
** My_Hunter
** File description:
** background
*/

#include "../include/my.h"

background_t *generate_background(void)
{
    background_t *background = malloc(sizeof(background_t));
    sfTexture *texture;

    texture = sfTexture_createFromFile("./content/background.jpg", NULL);
    background->sprite = sfSprite_create();
    sfSprite_setTexture(background->sprite, texture, sfTrue);
    background->pos.x = 0;
    background->pos.y = 0;
    background->scale.x = 1.62;
    background->scale.y = 1.62;
    sfSprite_setPosition(background->sprite, background->pos);
    sfSprite_setScale(background->sprite, background->scale);
    return background;
}
