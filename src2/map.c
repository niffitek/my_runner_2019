/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/game.h"

int count_rows(char *map)
{
    int counter = 0;

    for (int i = 0; map[i] != '\0'; i += 1)
        if (map[i] == '\n')
            counter += 1;
    return (counter);
}

int count_map(char *map)
{
    int counter = 0;

    for (int i = 0; map[i] != '\0'; i += 1) {
        if (map[i] != '\n' && map[i] != ' ')
            counter += 1;
    }
    return (counter);
}

int collision(objects *object)
{
    sfVector2f tile_pos;
    sfVector2f player_pos = sfSprite_getPosition(object->player.sprite);

    if (player_pos.y + 90 > 1080)
        return (1);
    for (int i = 0; object->tiles[i]; i += 1) {
        tile_pos = sfSprite_getPosition(object->tiles[i]->sprite);
        if (player_pos.x + 60 == tile_pos.x)
            if (player_pos.y + 90 > tile_pos.y + 10)
                return (1);
    }
    return (0);
}

int win(objects *object)
{
    sfVector2f player_pos = sfSprite_getPosition(object->player.sprite);
    sfVector2f win_pos;

    for (int i = 0; object->tiles[i]; i += 1) {
        if (object->tiles[i]->type == 4) {
            win_pos = sfSprite_getPosition(object->tiles[i]->sprite);
            if (player_pos.x == win_pos.x - 60)
                return (1);
        }
    }
    return (0);
}

char **map_to_array(char *buffer)
{
    int rows = count_rows(buffer);
    int col = 0;
    int tmp = 0;
    int i = 0;
    char **map = malloc(sizeof(char *) * (rows + 1));

    map[rows] = NULL;
    for (int r = 0; r < rows; r += 1, i += 1) {
        tmp = i;
        for (col = 0; buffer[tmp] != '\n' && buffer[tmp] != '\0'; tmp += 1,
            col += 1);
        map[r] = malloc(sizeof(char) * (col + 2));
        for (int c = 0; buffer[i] != '\n'; i += 1, c += 1)
            map[r][c] = buffer[i];
        map[r][col] = '\n';
        map[r][col + 1] = '\0';
    }
    return (map);
}