/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** load_entities into scene
*/

#include "starset_engine.h"
#include "warlock.h"
#include "scene.h"
#include "path.h"
#include "game_macro.h"
#include "render.h"

static void set_propreties(entities_t *entities)
{
    starset_entities_teleport(entities, "player", 400, 900);
    starset_entities_teleport(entities, "sora", 1500, 300);
    starset_entities_get_propreties(entities, "player")->speed = 3;
    starset_entities_get_propreties(entities, "sora")->life = 300;
}

entities_t *load_entities_scene(int zombie, sfRenderWindow *window)
{
    entities_t *entities = NULL;

    sfRenderWindow_clear(window, sfBlack);
    draw_loading_text(window);
    entities = create_zombie_scene(entities, zombie, window);
    entities = starset_entities_add(entities, DOG_PATH, "dog", false);
    entities = starset_entities_add(entities, GIRL_PATH, "sora", false);
    entities = starset_entities_add(entities, PLAYER_PATH, "player", false);
    entities = starset_entities_add(entities, BULLET_PATH, "bullet", false);
    entities = starset_entities_add(entities, "assets/building/Walls/1.png",
                                                    "border_right", false);
    entities = starset_entities_add(entities, "assets/building/Walls/2.png",
                                                    "wall", false);
    entities = starset_entities_add(entities, "assets/building/Walls/3.png",
                                                    "down_right", false);
    entities = starset_entities_add(entities, "assets/building/Walls/4.png",
                                                    "down_wall", false);
    entities = starset_entities_add(entities, "assets/building/Walls/X.png",
                                                    "border_left", false);
    entities = starset_entities_add(entities, "assets/building/Walls/Z.png",
                                                    "down_left", false);
    set_dog(entities);
    set_zombie_animation(entities);
    set_zombie_sound(entities, zombie);
    set_player_animation(entities);
    set_player_sound(entities);
    set_girl_animation(entities);
    set_girl_sound(entities);
    set_propreties(entities);
    return (entities);
}
