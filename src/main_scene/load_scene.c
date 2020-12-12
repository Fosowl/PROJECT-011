/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** load_scene
*/

#include "game_struct.h"
#include "inventory.h"
#include "scene.h"
#include "starset_engine.h"
#include "render.h"
#include "game_macro.h"
#include "warlock.h"
#include "path.h"

static void load_value(game_t *game)
{
    game->player.angle = 0.0f;
    game->player.control.key_up = sfKeyZ;
    game->player.control.key_down = sfKeyS;
    game->player.control.key_left = sfKeyQ;
    game->player.control.key_right = sfKeyD;
    game->player.control.key_reload = sfKeyR;
    game->player.control.key_inventory = sfKeyI;
    game->player.control.key_map = sfKeyM;
    game->player.control.key_weapon[0] = sfKeyNum1;
    game->player.control.key_weapon[1] = sfKeyNum2;
    game->player.control.key_weapon[2] = sfKeyNum3;
    game->player.control.key_weapon[3] = sfKeyNum4;
    game->player.selected = fill("pistol");
    game->player.ear_off = false;
    game->player.nb_magazine_gun = 1;
    game->player.nb_magazine_rifle = 1;
    game->player.ammo_gun = 11;
    game->player.ammo_rifle = 30;
    game->player.unlock_rifle = false;
}

static void load_ui(ui_t *ui, sfRenderWindow *window)
{
    sfVector2u screen_size = sfRenderWindow_getSize(window);

    ui->over_texture = sfTexture_createFromFile(GAME_OVER_PATH, NULL);
    ui->over_sprite = sfSprite_create();
    if (!ui->over_texture)
        put_error("failed to load texture !\n");
    ui->over_vector = (sfVector2f){(screen_size.x / 2) - 200
    , (screen_size.y / 2) + 30};
    sfSprite_setTexture(ui->over_sprite, ui->over_texture, 1);
    ui->over_rect.width = 414;
    ui->over_rect.height = 78;
    ui->over_rect.left = 0;
    ui->over_rect.top = 0;
    sfSprite_setPosition(ui->over_sprite, ui->over_vector);
}

static void load_value_2(game_t *game)
{
    load_ui(&game->ui, game->screen->window);
    game->girl = starset_entities_get_propreties(game->entities_list, "sora");
    game->bullet = starset_entities_get_propreties(game->entities_list
    , "bullet");
    game->player.save = starset_entities_get_propreties(game->entities_list
    , "player");
    game->entities_runtime = NULL;
}

int main_scene_load(game_t *game)
{
    sfClock *timer = sfClock_create();
    game->entities_list = load_entities_scene(20, game->screen->window);

    if (!game->entities_list)
        return EXIT_FAILURE;
    srand(time(NULL));
    introduction_scene(game);
    load_value(game);
    load_value_2(game);
    create_case_element(game->inventory);
    if (main_scene_loop(game, timer) == EXIT_CLOSE) {
        starset_entities_destroy_all(game->entities_list);
        return EXIT_CLOSE;
    }
    starset_entities_destroy_all(game->entities_list);
    return EXIT_SUCCESS;
}
