/*
** EPITECH PROJECT, 2025
** My_Hunter
** File description:
** start_button
*/

#include "../include/my.h"

static void init_button_sprite(button_t *button, sfTexture *texture)
{
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, texture, sfTrue);
    button->rect = malloc(sizeof(sfIntRect));
    button->rect->top = 0;
    button->rect->left = 0;
    button->rect->width = 1122;
    button->rect->height = 1000;
    sfSprite_setTextureRect(button->sprite, *button->rect);
    button->pos.x = 750;
    button->pos.y = 700;
    button->scale.x = 0.4;
    button->scale.y = 0.4;
}

button_t *generate_button(void)
{
    button_t *button = malloc(sizeof(button_t));
    sfTexture *texture;

    texture = sfTexture_createFromFile("./content/start.png", NULL);
    init_button_sprite(button, texture);
    button->clock = sfClock_create();
    button->sound_buffer =
        sfSoundBuffer_createFromFile("./content/start_button.mp3");
    button->sound = sfSound_create();
    sfSound_setBuffer(button->sound, button->sound_buffer);
    sfSprite_setPosition(button->sprite, button->pos);
    sfSprite_setScale(button->sprite, button->scale);
    return button;
}

static bool handle_button_press(button_t *button, bool *was_pressed,
    bool *sound_played)
{
    sfIntRect start_rect = sfSprite_getTextureRect(button->sprite);

    start_rect.left = 1122;
    button->pos.x = 755;
    button->pos.y = 720;
    sfSprite_setTextureRect(button->sprite, start_rect);
    sfSprite_setPosition(button->sprite, button->pos);
    if (*was_pressed == false && *sound_played == false) {
        sfSound_play(button->sound);
        *was_pressed = true;
        *sound_played = true;
    }
    return true;
}

static void reset_button(button_t *button, bool *was_pressed)
{
    sfIntRect start_rect = sfSprite_getTextureRect(button->sprite);

    start_rect.left = 0;
    sfSprite_setTextureRect(button->sprite, start_rect);
    start_rect.left = 1122;
    button->pos.x = 750;
    button->pos.y = 700;
    sfSprite_setPosition(button->sprite, button->pos);
    *was_pressed = false;
}

bool change_button_sprite(sfRenderWindow *window, button_t *button,
    bool start_counter)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect start_bounds = sfSprite_getGlobalBounds(button->sprite);
    static bool was_pressed = false;
    static bool sound_played = false;

    if (start_counter)
        return start_counter;
    if (mouse_pos.x >= start_bounds.left &&
        mouse_pos.x <= start_bounds.left + start_bounds.width &&
        mouse_pos.y >= start_bounds.top &&
        mouse_pos.y <= start_bounds.top + start_bounds.height) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            return handle_button_press(button, &was_pressed, &sound_played);
        }
        reset_button(button, &was_pressed);
    }
    return start_counter;
}
