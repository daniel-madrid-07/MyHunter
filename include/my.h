/*
** EPITECH PROJECT, 2022
** MY_H
** File description:
** desc
*/

#ifndef MY_H_
    # define MY_H_

    #include <stdarg.h>
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Sprite.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System.h>
    #include <SFML/System/Clock.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <math.h>

typedef struct kirby_s {
    sfSprite *sprite;
    sfIntRect *rect;
    sfClock *clock;
    sfVector2f pos;
    sfVector2f scale;
    float speed_x;
    float speed_y;
    int direction;
    int movement_pattern; // 0: wave, 1: ellipse, 2: zigzag
    float movement_timer;
    float amplitude;
    float frequency;
    sfTexture *texture;
} kirby_t;

typedef struct counter_s {
    sfSprite *sprite;
    sfIntRect *rect;
    sfClock *clock;
    sfVector2f pos;
    sfVector2f scale;
} counter_t;

typedef struct button_s {
    sfSprite *sprite;
    sfIntRect *rect;
    sfClock *clock;
    sfVector2f pos;
    sfVector2f scale;
    sfSound *sound;
    sfSoundBuffer *sound_buffer;
} button_t;

typedef struct text_s {
    sfText *text;
    sfIntRect *rect;
    sfClock *clock;
    sfVector2f pos;
    sfVector2f scale;
} text_t;

typedef struct background_s {
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f scale;
} background_t;

typedef struct crosshair_s {
    sfSprite *sprite;
    sfIntRect *rect;
    sfClock *clock;
    sfVector2f pos;
    sfVector2f scale;
    sfSound *sound;
    sfSoundBuffer *sound_buffer;
} crosshair_t;

typedef struct bullets_s {
    sfSprite *sprite_filled;
    sfSprite *sprite_empty;
    sfTexture *texture_filled;
    sfTexture *texture_empty;
    sfVector2f pos;
    sfVector2f scale;
    int misses;
} bullets_t;

typedef struct game_data_s {
    kirby_t *kirbys[10];
    int active_kirbys;
    sfClock *spawn_clock;
    float speed_multiplier;
    int miss_count;
    bool game_over;
    int spawn_counter;
} game_data_t;

game_data_t *get_game_data(void);

void counter(sfClock *clock, sfSprite *counter_sprite,
    sfIntRect *counter_rect);
void change_kirby_sprite(sfClock *clock, sfSprite *kirby_sprite,
    sfIntRect *kirby_rect);
bool change_button_sprite(sfRenderWindow *window, button_t *button,
    bool start_counter);
void change_crosshair_sprite(crosshair_t *crosshair,
    sfRenderWindow *window);
kirby_t *generate_kirby(void);
button_t *generate_button(void);
text_t *generate_text(void);
counter_t *generate_counter(void);
background_t *generate_background(void);
crosshair_t *generate_crosshair(void);

// Bullets functions
bullets_t *generate_bullets(void);
void draw_bullets(sfRenderWindow *window, bullets_t *bullets);
void update_bullets_on_miss(bullets_t *bullets);
void destroy_bullets(bullets_t *bullets);

// Game functions
void init_game(void);
void spawn_kirbys(void);
void update_kirbys(void);
void draw_kirbys(sfRenderWindow *window);
int handle_kirby_click(sfRenderWindow *window, sfEvent *event,
    crosshair_t *crosshair, bullets_t *bullets);
bool is_counter_finished(sfIntRect *counter_rect);
bool is_game_over(void);
int get_miss_count(void);
int get_escape_count(void);
void cleanup_game(void);
void remove_kirby(int i);
void update_single_kirby(int i);
int check_hit(int i, sfVector2f pos, crosshair_t *crosshair);
void set_kirby_left_direction(kirby_t *new_kirby);
void set_kirby_right_direction(kirby_t *new_kirby);

void update_score_text(text_t *text, int score);
sfText *create_game_over_text(int final_score, int misses,
    int escapes);
void int_to_str(int num, char *str);
char *my_strcat(char *dest, char *src);
int my_printf(const char *format, ...);

struct objects_s {
    kirby_t *kirby;
    button_t *button;
    background_t *background;
    text_t *text;
    counter_t *counter_f;
    crosshair_t *crosshair;
    bullets_t *bullets;
    sfRenderWindow *window;
    sfMusic *music;
    sfMusic *game_over_music;
};

struct game_state_s {
    bool button_clicked;
    bool start_counter;
    bool game_started;
    int score;
    sfText *game_over_text;
    bool music_changed;
    bool paused;
    sfText *exit_text;
};

void render_game_objects(sfRenderWindow *window, bool game_started,
    struct objects_s *obj);
void render_counter_ui(sfRenderWindow *window, bool start_counter,
    bool game_started, struct objects_s *obj);
void update_initial_kirby(struct objects_s *obj);
void process_hit(struct game_state_s *state, struct objects_s *obj,
    int hit);
sfText *create_exit_text(void);
void print_help(void);
void print_help_rules(void);
int check_args(int ac, char **av);
sfRenderWindow *create_window(void);
void init_music(struct objects_s *obj);

#endif
