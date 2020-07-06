/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** struct
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#ifndef MUL_MY_HUNTER_2019_STRUCTS_H
#define MUL_MY_HUNTER_2019_STRUCTS_H

typedef struct player_s
{
    sfSprite *sprite;
    sfIntRect anim;
    sfVector2f gravity;
    double tmptime;
} player_t;

typedef struct tile_s
{
    sfVector2f pos;
    int type;
    sfSprite *sprite;
} tile;

typedef struct text_s
{
    sfFont *font;
    sfVector2f pos;
    sfText *text;
} ui_text;

typedef struct objects_s
{
    sfRenderWindow *window;
    sfSprite *background;
    sfSprite *background2;
    sfSprite *midground;
    sfSprite *midground2;
    sfMusic *music;
    sfMusic *sound;
    tile **tiles;
    ui_text texts[5];
    char *score_texts;
    char *highscore_texts;
    int score;
    int highscore;
    int tile_count;
    char **map;
    sfEvent event;
    sfClock *clock;
    sfTime gametime;
    player_t player;
} objects;

#endif //MUL_MY_HUNTER_2019_STRUCTS_H
