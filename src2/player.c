/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/game.h"

player_t create_player(void)
{
    player_t new;
    sfTexture *player_image = sfTexture_createFromFile("assets/player.png",
        NULL);
    new.sprite = sfSprite_create();
    new.anim.left = 0;
    new.anim.top = 0;
    new.anim.width = 12;
    new.anim.height = 19;
    new.tmptime = 0;
    new.gravity.x = 0;
    new.gravity.y = 10;
    sfVector2f scale = {5, 5};
    sfVector2f pos = {100, 810};

    sfSprite_setTexture(new.sprite, player_image, sfFalse);
    sfSprite_setTextureRect(new.sprite, new.anim);
    sfSprite_setScale(new.sprite, scale);
    sfSprite_setPosition(new.sprite, pos);
    return (new);
}

void animate_player(objects *object)
{
    if (object->player.anim.left > 41)
        object->player.anim.left = 0;
    else
        object->player.anim.left += 16;
    sfSprite_setTextureRect(object->player.sprite, object->player.anim);
}

int get_ground(objects *object)
{
    sfVector2f pos;

    for (int i = 0; object->tiles[i]; i += 1) {
        pos = sfSprite_getPosition(object->tiles[i]->sprite);
        if (pos.x > 19 && pos.x < 120)
            return (pos.y);
    }
    return (1100);
}

int is_on_ground(objects *object)
{
    int ground = get_ground(object);
    sfVector2f pos = sfSprite_getPosition(object->player.sprite);

    if (pos.y + 90 < ground)
        return (0);
    if (pos.y + 90 > ground) {
        pos.y = ground - 90;
        sfSprite_setPosition(object->player.sprite, pos);
    }
    return (1);
}

void player_controller(objects *object)
{
    double seconds = object->gametime.microseconds / 1000000.0;

    if (!is_on_ground(object)) {
        sfSprite_move(object->player.sprite, object->player.gravity);
        object->player.gravity.y = do_jump(object);
        object->player.anim.left = 74;
        sfSprite_setTextureRect(object->player.sprite, object->player.anim);
    } else
        sfMusic_stop(object->sound);
    if (seconds - object->player.tmptime > 0.2 && is_on_ground(object)) {
        animate_player(object);
        object->player.tmptime = seconds;
    }
    sfRenderWindow_drawSprite(object->window, object->player.sprite, NULL);
}