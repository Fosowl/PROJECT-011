/*
** EPITECH PROJECT, 2020
** engine
** File description:
** create_sound
*/

#include "../../include/macro.h"
#include "../../include/internal.h"

static void internal__set_value_audio(audio_t *audio, char *name)
{
    audio->name = fill_e(name);
    audio->loop = false;
    audio->playing = false;
    audio->volume = 70;
    audio->next = NULL;
    audio->timer = sfClock_create();
    audio->sound = sfSound_create();
}

static audio_t *internal__create_new_audio(char *name, char *path)
{
    audio_t *audio = malloc(sizeof(audio_t));
    sfSoundBuffer *buffer = NULL;

    if (!audio)
        return (NULL);
    internal__set_value_audio(audio, name);
    sfSound_setRelativeToListener(audio->sound, true);
    sfListener_setspot(audio->binaural);
    if (!audio->sound || !audio->timer || !audio->sound)
        return (NULL);
    buffer = sfSoundBuffer_createFromFile(path);
    if (!buffer) {
        put_err("failed to load audio file\n");
        return (NULL);
    }
    audio->duration = sfSoundBuffer_getDuration(buffer);
    audio->delay = audio->duration;
    sfSound_setBuffer(audio->sound, buffer);
    return (audio);
}

static audio_t *internal__push_audio(audio_t *audio, char *name, char *path)
{
    audio_t *copy = NULL;

    if (!audio) {
        audio = internal__create_new_audio(name, path);
        return (audio);
    } else {
        for (copy = audio; copy->next != NULL; copy = copy->next);
        copy->next = internal__create_new_audio(name, path);
    }
    return (audio);
}

void starset_add_entities_sound(entities_t *entities, char *name
, char *sound_name, char *path)
{
    sfBool ok = false;
    char **get = internal__get_class(name);

    for (entities_t *copy = entities; copy != NULL; copy = copy->next) {
        if (search_e(get[0], copy->name) != -1 || search_e(copy->name
        , get[1]) != -1) {
            copy->audio = internal__push_audio(copy->audio, sound_name, path);
            ok = true;
        }
    }
    (!ok && !!LOG) ? put_err("bad entities in starset_add_sound()\n") : 0;
}

static audio_t *internal__get_audio(audio_t *audio, char *name)
{
    sfBool ok = false;
    char **get = internal__get_class(name);
    audio_t *tmp = NULL;

    for (audio_t *copy = audio; copy != NULL; copy = copy->next) {
        if (search_e(get[0], copy->name) != -1 || search_e(copy->name
        , get[1]) != -1) {
            tmp = copy;
            ok = true;
        }
    }
    (!ok && !!LOG) ? put_err("bad sound name in starset_set_sound_volume()\n") : 0;
    return (tmp);
}

void starset_set_sound_volume(entities_t *entities, char *name
, char *sound_name, int volume)
{
    sfBool ok = false;
    char **get = internal__get_class(name);
    audio_t *audio = NULL;

    for (entities_t *copy = entities; copy != NULL; copy = copy->next) {
        if (search_e(get[0], copy->name) != -1 || search_e(copy->name
        , get[1]) != -1) {
            audio = internal__get_audio(copy->audio, sound_name);
            ok = true;
        }
    }
    audio->volume = volume;
    (!ok && !!LOG) ? put_err("bad entities in starset_set_sound_volume()\n") : 0;
}