/*
** EPITECH PROJECT, 2025
** Graphical_Programming
** File description:
** Game cleanup and hit detection
*/

#include "../include/my.h"

static int is_kirby_exists(int i)
{
    if (get_game_data()->kirbys[i] == NULL)
        return 0;
    return 1;
}

static int is_click_inside_kirby(kirby_t *kirby, sfVector2f click_pos)
{
    sfFloatRect kirby_bounds = sfSprite_getGlobalBounds(kirby->sprite);

    if (sfFloatRect_contains(&kirby_bounds, click_pos.x, click_pos.y))
        return 1;
    return 0;
}

static void play_hit_sound(crosshair_t *crosshair)
{
    if (crosshair->sound)
        sfSound_play(crosshair->sound);
}

static void increase_game_speed(void)
{
    get_game_data()->speed_multiplier += 0.2f;
}

int check_hit(int i, sfVector2f click_pos, crosshair_t *crosshair)
{
    kirby_t *kirby;

    if (is_kirby_exists(i) == 0)
        return 0;
    kirby = get_game_data()->kirbys[i];
    if (is_click_inside_kirby(kirby, click_pos) == 1) {
        play_hit_sound(crosshair);
        remove_kirby(i);
        increase_game_speed();
        return 1;
    }
    return 0;
}

static void del_clock(void)
{
    if (get_game_data()->spawn_clock != NULL) {
        sfClock_destroy(get_game_data()->spawn_clock);
        get_game_data()->spawn_clock = NULL;
    }
}

static void reset_state(void)
{
    get_game_data()->active_kirbys = 0;
    get_game_data()->speed_multiplier = 1.0f;
    get_game_data()->miss_count = 0;
    get_game_data()->game_over = false;
}

void cleanup_game(void)
{
    int i;

    for (i = 0; i < 10; i++) {
        if (get_game_data()->kirbys[i] != NULL)
            remove_kirby(i);
    }
    del_clock();
    reset_state();
}
