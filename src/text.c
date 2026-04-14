/*
** EPITECH PROJECT, 2025
** My_Hunter
** File description:
** text
*/

#include "../include/my.h"

static int my_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return i;
}

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int j = my_strlen(dest);

    while (src[i]) {
        dest[j + i] = src[i];
        i++;
    }
    dest[j + i] = '\0';
    return dest;
}

static void reverse_str(char *str, int i)
{
    int j;
    char temp;

    for (j = 0; j < i / 2; j++) {
        temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
}

static void add_digit(char *str, int *i, int num)
{
    str[*i] = (num % 10) + '0';
    *i = *i + 1;
}

static void add_minus(char *str, int *i)
{
    str[*i] = '-';
    *i = *i + 1;
}

void int_to_str(int num, char *str)
{
    int i = 0;
    int is_negative = 0;

    if (num == 0) {
        str[0] = '0';
        str[1] = '\0';
        return;
    }
    if (num < 0) {
        is_negative = 1;
        num = -num;
    }
    while (num > 0) {
        add_digit(str, &i, num);
        num /= 10;
    }
    if (is_negative)
        add_minus(str, &i);
    str[i] = '\0';
    reverse_str(str, i);
}

static void init_text_position(sfVector2f *text_position)
{
    text_position->x = 50;
    text_position->y = 5;
}

static void setup_score_text(sfText *score_text, sfVector2f text_position)
{
    sfText_setString(score_text, "DEAD KIRBYS  0");
    sfText_setCharacterSize(score_text, 60);
    sfText_setFillColor(score_text, sfWhite);
    sfText_setPosition(score_text, text_position);
}

text_t *generate_text(void)
{
    text_t *text = malloc(sizeof(text_t));
    sfFont *font;
    sfText *score_text;
    sfVector2f text_position;

    init_text_position(&text_position);
    if (text == NULL)
        return NULL;
    font = sfFont_createFromFile("./content/font.TTF");
    if (font == NULL)
        return NULL;
    score_text = sfText_create();
    if (score_text == NULL)
        return NULL;
    sfText_setFont(score_text, font);
    setup_score_text(score_text, text_position);
    text->text = score_text;
    return text;
}
