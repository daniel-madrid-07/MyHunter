/*
** EPITECH PROJECT, 2025
** My_Hunter
** File description:
** start_crosshair
*/

#include "../include/my.h"

static void init_crosshair_sprite(crosshair_t *crosshair, sfTexture *texture)
{
    crosshair->sprite = sfSprite_create();
    sfSprite_setTexture(crosshair->sprite, texture, sfTrue);
    crosshair->rect = malloc(sizeof(sfIntRect));
    crosshair->rect->top = 0;
    crosshair->rect->left = 0;
    crosshair->rect->width = 14;
    crosshair->rect->height = 13;
    sfSprite_setTextureRect(crosshair->sprite, *crosshair->rect);
}

crosshair_t *generate_crosshair(void)
{
    crosshair_t *crosshair = malloc(sizeof(crosshair_t));
    sfTexture *texture;

    texture = sfTexture_createFromFile("./content/crosshair.png", NULL);
    init_crosshair_sprite(crosshair, texture);
    crosshair->pos.x = 0;
    crosshair->pos.y = 0;
    crosshair->scale.x = 6.0;
    crosshair->scale.y = 6.0;
    crosshair->clock = sfClock_create();
    crosshair->sound_buffer =
        sfSoundBuffer_createFromFile("./content/shot.mp3");
    crosshair->sound = sfSound_create();
    sfSound_setBuffer(crosshair->sound, crosshair->sound_buffer);
    sfSound_setVolume(crosshair->sound, 10.f);
    sfSprite_setPosition(crosshair->sprite, crosshair->pos);
    sfSprite_setScale(crosshair->sprite, crosshair->scale);
    return crosshair;
}

static void update_crosshair_pos(crosshair_t *crosshair,
    sfRenderWindow *window)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    crosshair->pos.x = mouse_pos.x -
        (crosshair->rect->width * crosshair->scale.x) / 2;
    crosshair->pos.y = mouse_pos.y -
        (crosshair->rect->height * crosshair->scale.y) / 2;
    sfSprite_setPosition(crosshair->sprite, crosshair->pos);
}

void change_crosshair_sprite(crosshair_t *crosshair, sfRenderWindow *window)
{
    sfIntRect crosshair_rect = sfSprite_getTextureRect(crosshair->sprite);
    sfTime elapsed = sfClock_getElapsedTime(crosshair->clock);
    float time_seconds = sfTime_asSeconds(elapsed);

    update_crosshair_pos(crosshair, window);
    if (time_seconds >= 0.2f && crosshair_rect.left == 14) {
        crosshair_rect.left = 0;
        sfSprite_setTextureRect(crosshair->sprite, crosshair_rect);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (crosshair_rect.left == 0 || time_seconds >= 0.2f) {
            crosshair_rect.left = 14;
            sfSprite_setTextureRect(crosshair->sprite, crosshair_rect);
            sfSound_play(crosshair->sound);
            sfClock_restart(crosshair->clock);
        }
    }
}
