/*
** EPITECH PROJECT, 2025
** Graphical_Programming
** File description:
** Game utilities
*/

#include "../include/my.h"

void draw_kirbys(sfRenderWindow *window)
{
    int i;
    kirby_t *k;

    for (i = 0; i < 10; i++) {
        k = get_game_data()->kirbys[i];
        if (k != NULL)
            sfRenderWindow_drawSprite(window, k->sprite, NULL);
    }
}

bool is_counter_finished(sfIntRect *counter_rect)
{
    return (counter_rect->left >= 540);
}

bool is_game_over(void)
{
    return get_game_data()->game_over;
}

int get_miss_count(void)
{
    return get_game_data()->miss_count;
}

int get_escape_count(void)
{
    return 0;
}
