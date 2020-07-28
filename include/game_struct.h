/*
** EPITECH PROJECT, 2020
** include
** File description:
** game_struct
*/

#ifndef GAME_STRUCT_H_
#define GAME_STRUCT_H_

#include "starset_engine.h"

typedef struct basic_object_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f vector;
    sfIntRect rect;
} basic_object_t;

typedef struct check_text_s{
    int draw;
} check_text_t;

typedef struct element_inventory_s {
    basic_object_t *init;
    basic_object_t *object;
    basic_object_t *info;
    int status;
    int draw;
    sfText *number;
    int type;
    int class;
    int nb;
    int destroy;
    int destroy_info;
} element_inventory_t;

typedef struct contains_inventory_s {
    int nb;
    int nb_case;
    int max;
    int status;
} contains_inventory_t;


typedef struct inventory_s {
    basic_object_t *background;
    element_inventory_t *element;
    basic_object_t *button_all;
    basic_object_t *move;
    int button;
    int location;
    contains_inventory_t *contains;
} inventory_t;

typedef struct hover_s {
    sfTexture *play_texture;
    sfSprite *play_sprite;
    sfVector2f play_pos;
    sfTexture *quit_texture;
    sfSprite *quit_sprite;
    sfVector2f quit_pos;
    sfTexture *load_texture;
    sfSprite *load_sprite;
    sfVector2f load_pos;
    sfTexture *how_texture;
    sfSprite *how_sprite;
    sfVector2f how_pos;
} hover_t;

typedef struct how_s {
    sfTexture *how_bg_texture;
    sfSprite *how_bg_sprite;
    sfTexture *press_space_texture;
    sfSprite *press_space_sprite;
    sfVector2f press_space_pos;
} how_t;

typedef struct pause_s {
    sfTexture *bg_texture;
    sfSprite *bg_sprite;
    sfVector2f bg_pos;
    sfTexture *continue_texture;
    sfSprite *continue_sprite;
    sfVector2f continue_pos;
    sfTexture *quit_game_texture;
    sfSprite *quit_game_sprite;
    sfVector2f quit_game_pos;
} pause_t;

typedef struct menu_s {
    sfTexture *menu_texture;
    sfSprite *menu_sprite;
    sfSound *menu_music;
    sfTexture *play_texture;
    sfSprite *play_sprite;
    sfVector2f play_pos;
    sfTexture *quit_texture;
    sfSprite *quit_sprite;
    sfVector2f quit_pos;
    sfTexture *load_texture;
    sfSprite *load_sprite;
    sfVector2f load_pos;
    sfTexture *how_texture;
    sfSprite *how_sprite;
    sfVector2f how_pos;
    hover_t *hover_menu;
    how_t *how_to;
    pause_t *pause_m;
} menu_t;

typedef struct screen_s {
    sfVideoMode mode;
    sfRenderWindow *window;
} screen_t;

typedef struct control_t {
    int key_up;
    int key_down;
    int key_left;
    int key_right;
    int key_weapon[5];
    int key_map;
    int key_inventory;
    int key_reload;
} control_t;

typedef struct player_t {
    char *selected;
    control_t control;
    entities_t *save;
    int status;
    float angle;
    sfBool ear_off;
    float noise;
    int ammo_gun;
    int ammo_rifle;
    int nb_magazine_gun;
    int nb_magazine_rifle;
    sfBool unlock_rifle;
} player_t;


typedef struct ui_ammo_t {
    char *str_mag;
    char *str_total;
    sfVector2u s;
    sfVector2f p_ui[2];
} ui_ammo_t;

typedef struct ui_t {
    sfTexture *over_texture;
    sfSprite *over_sprite;
    sfVector2f over_vector;
    sfIntRect over_rect;
} ui_t;

typedef struct game_s {
    screen_t *screen;
    menu_t *menu;
    inventory_t *inventory;
    sfRenderWindow *window;
    sfVector2i mouse_pos;
    sfVector2i window_pos;
    sfEvent event;
    entities_t *entities_list;
    entities_t *entities_runtime;
    sfTime runtime;
    int mode;
    int delay;
    entities_t *girl;
    entities_t *bullet;
    player_t player;
    ui_t ui;
} game_t;

#endif /* !GAME_STRUCT_H_ */
