/*
** EPITECH PROJECT, 2019
** rpg_en_cours
** File description:
** event_inventory.c
*/

#include "game_struct.h"
#include "game_macro.h"
#include "inventory.h"

void event_button_inventory(game_t *game)
{
    sfVector2i pos_mouse;
    sfVector2f pos_bag;
    sfVector2f rec_bag;

    if (press(sfKeyI)) {
        if (game->inventory->button == 1)
            game->inventory->button = 0;
        else
            game->inventory->button = 1;
    }
}