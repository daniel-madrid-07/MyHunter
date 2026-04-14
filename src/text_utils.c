/*
** EPITECH PROJECT, 2025
** My_Hunter
** File description:
** text utilities
*/

#include "../include/my.h"

void update_score_text(text_t *text, int score)
{
    char buffer[50] = "DEAD KIRBYS  ";
    char num_str[20];

    int_to_str(score, num_str);
    my_strcat(buffer, num_str);
    sfText_setString(text->text, buffer);
}

static void add_miss_or_escape(char *buffer, int misses, int escapes)
{
    if (misses >= 3)
        my_strcat(buffer, "\n3 MISSES!");
    if (escapes >= 3)
        my_strcat(buffer, "\n3 KIRBYS ESCAPED!");
}

static void init_gameover_position(sfVector2f *text_position)
{
    text_position->x = 550;
    text_position->y = 400;
}

static void setup_gameover_text(sfText *game_over, sfVector2f text_position)
{
    sfText_setCharacterSize(game_over, 70);
    sfText_setFillColor(game_over, sfRed);
    sfText_setPosition(game_over, text_position);
}

sfText *create_game_over_text(int final_score, int misses, int escapes)
{
    sfFont *font = sfFont_createFromFile("./content/font.TTF");
    sfText *game_over;
    char buffer[150] = "GAME OVER!\nFinal Score ";
    char num_str[20];
    sfVector2f text_position;

    init_gameover_position(&text_position);
    if (font == NULL)
        return NULL;
    game_over = sfText_create();
    if (game_over == NULL)
        return NULL;
    int_to_str(final_score, num_str);
    my_strcat(buffer, num_str);
    add_miss_or_escape(buffer, misses, escapes);
    sfText_setFont(game_over, font);
    sfText_setString(game_over, buffer);
    setup_gameover_text(game_over, text_position);
    return game_over;
}
