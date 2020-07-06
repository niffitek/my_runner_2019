/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/game.h"

sfSprite *create_background(void)
{
    sfTexture *bg = sfTexture_createFromFile("assets/background.png", NULL);
    sfSprite *background = sfSprite_create();
    sfSprite_setTexture(background, bg, sfFalse);
    return (background);
}

void move_background(objects *object)
{
    sfVector2f move = {-2, 0};
    sfVector2f pos = {1920, 0};

    sfRenderWindow_clear(object->window, sfBlack);
    sfRenderWindow_drawSprite(object->window, object->background, NULL);
    sfRenderWindow_drawSprite(object->window, object->background2, NULL);
    sfSprite_move(object->background, move);
    sfSprite_move(object->background2, move);
    if (sfSprite_getPosition(object->background).x == -1920)
        sfSprite_setPosition(object->background, pos);
    if (sfSprite_getPosition(object->background2).x == -1920)
        sfSprite_setPosition(object->background2, pos);
}

sfSprite *create_midground(void)
{
    sfVector2f scale = {4, 4};
    sfVector2f pos = {0, 0};

    sfTexture *bg = sfTexture_createFromFile("assets/midground.png", NULL);
    sfSprite *background = sfSprite_create();
    sfSprite_setTexture(background, bg, sfFalse);
    sfSprite_setScale(background, scale);
    sfSprite_setPosition(background, pos);
    return (background);
}

void move_midground(objects *object)
{
    sfVector2f move = {-3, 0};
    sfVector2f pos = {1920, 0};

    sfRenderWindow_drawSprite(object->window, object->midground, NULL);
    sfRenderWindow_drawSprite(object->window, object->midground2, NULL);
    sfSprite_move(object->midground, move);
    sfSprite_move(object->midground2, move);
    if (sfSprite_getPosition(object->midground).x == -1920)
        sfSprite_setPosition(object->midground, pos);
    if (sfSprite_getPosition(object->midground2).x == -1920)
        sfSprite_setPosition(object->midground2, pos);
}

void move_map(objects *object)
{
    sfVector2f move = {-4, 0};

    for (int i = 0; i < object->tile_count - 1; i += 1) {
        sfRenderWindow_drawSprite(object->window, object->tiles[i]->sprite,
            NULL);
        sfSprite_move(object->tiles[i]->sprite, move);
    }
}