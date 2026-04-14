/*
** EPITECH PROJECT, 2025
** Graphical_Programming
** File description:
** Initialization functions
*/

#include "../include/my.h"

sfRenderWindow *create_window(void)
{
    sfVideoMode mode;
    sfRenderWindow *window;

    mode.width = 1920;
    mode.height = 1080;
    mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(mode, "My Hunter", sfResize | sfClose,
        NULL);
    sfRenderWindow_setFramerateLimit(window, 240);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    return window;
}

void init_music(struct objects_s *obj)
{
    obj->music = sfMusic_createFromFile("./content/music.mp3");
    obj->game_over_music =
        sfMusic_createFromFile("./content/gameover.mp3");
    sfMusic_setLoop(obj->music, sfTrue);
    sfMusic_setVolume(obj->music, 40.f);
    sfMusic_setVolume(obj->game_over_music, 40.f);
    sfMusic_play(obj->music);
}
