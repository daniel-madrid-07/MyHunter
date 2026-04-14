/*
** EPITECH PROJECT, 2025
** Graphical_Programming
** File description:
** Bullets
*/

#include "../include/my.h"

static sfSprite *init_bullet_sprite(sfTexture *texture, sfVector2f pos,
    sfVector2f scale)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, scale);
    return sprite;
}

static int load_bullet_textures(bullets_t *bullets)
{
    bullets->texture_filled =
        sfTexture_createFromFile("./content/bullets-filled.png", NULL);
    bullets->texture_empty =
        sfTexture_createFromFile("./content/bullets-empty.png", NULL);
    if (bullets->texture_filled == NULL || bullets->texture_empty == NULL) {
        if (bullets->texture_filled != NULL)
            sfTexture_destroy(bullets->texture_filled);
        if (bullets->texture_empty != NULL)
            sfTexture_destroy(bullets->texture_empty);
        free(bullets);
        return 84;
    }
    return 0;
}

bullets_t *generate_bullets(void)
{
    bullets_t *bullets = malloc(sizeof(bullets_t));

    if (bullets == NULL)
        return NULL;
    if (load_bullet_textures(bullets) != 0)
        return NULL;
    bullets->pos.x = 860;
    bullets->pos.y = 900;
    bullets->scale.x = 2.2f;
    bullets->scale.y = 2.2f;
    bullets->sprite_filled = init_bullet_sprite(bullets->texture_filled,
        bullets->pos, bullets->scale);
    bullets->sprite_empty = init_bullet_sprite(bullets->texture_empty,
        bullets->pos, bullets->scale);
    bullets->misses = 0;
    return bullets;
}

static void draw_one_miss(sfRenderWindow *window, bullets_t *bullets)
{
    sfIntRect rect;
    sfVector2u texture_size = sfTexture_getSize(bullets->texture_filled);

    rect.left = 0;
    rect.top = 0;
    rect.width = texture_size.x - 35;
    rect.height = texture_size.y;
    sfSprite_setTextureRect(bullets->sprite_filled, rect);
    sfRenderWindow_drawSprite(window, bullets->sprite_filled, NULL);
}

static void draw_two_misses(sfRenderWindow *window, bullets_t *bullets)
{
    sfIntRect rect;
    sfVector2u texture_size = sfTexture_getSize(bullets->texture_filled);

    rect.left = 0;
    rect.top = 0;
    rect.width = texture_size.x - 60;
    rect.height = texture_size.y;
    sfSprite_setTextureRect(bullets->sprite_filled, rect);
    sfRenderWindow_drawSprite(window, bullets->sprite_filled, NULL);
}

static void draw_bullets_by_misses(sfRenderWindow *window, bullets_t *bullets)
{
    if (bullets->misses == 0)
        sfRenderWindow_drawSprite(window, bullets->sprite_filled, NULL);
    if (bullets->misses == 1)
        draw_one_miss(window, bullets);
    if (bullets->misses == 2)
        draw_two_misses(window, bullets);
}

void draw_bullets(sfRenderWindow *window, bullets_t *bullets)
{
    if (bullets == NULL)
        return;
    sfRenderWindow_drawSprite(window, bullets->sprite_empty, NULL);
    draw_bullets_by_misses(window, bullets);
}

void update_bullets_on_miss(bullets_t *bullets)
{
    if (bullets == NULL)
        return;
    if (bullets->misses < 3)
        bullets->misses++;
}

void destroy_bullets(bullets_t *bullets)
{
    if (bullets == NULL)
        return;
    if (bullets->sprite_filled != NULL)
        sfSprite_destroy(bullets->sprite_filled);
    if (bullets->sprite_empty != NULL)
        sfSprite_destroy(bullets->sprite_empty);
    if (bullets->texture_filled != NULL)
        sfTexture_destroy(bullets->texture_filled);
    if (bullets->texture_empty != NULL)
        sfTexture_destroy(bullets->texture_empty);
    free(bullets);
}
