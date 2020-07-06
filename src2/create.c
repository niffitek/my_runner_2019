/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/game.h"

objects *build_game(char *av)
{
    char buffer[30000];
    int fd = open(av, O_RDONLY);
    int size = read(fd, buffer, 30000);

    buffer[size] = '\0';
    objects *object = malloc(sizeof(objects));
    object->window = create_window();
    object->background = create_background();
    object->background2 = create_background();
    object->midground = create_midground();
    object->midground2 = create_midground();
    object->clock = sfClock_create();
    object->map = map_to_array(buffer);
    object->tile_count = count_map(buffer);
    object->tiles = create_tiles(object);
    object->player = create_player();
    object->music = sfMusic_createFromFile("assets/music.ogg");
    object->sound = sfMusic_createFromFile("assets/jump.ogg");
    object = build_texts(object);
    return (object);
}

sfRenderWindow *create_window(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {1920, 1080, 32};

    window = sfRenderWindow_create(video_mode, "my_runner", sfDefaultStyle,
        NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

tile *create_tile_sprite(tile *new)
{
    sfTexture *tile1 = sfTexture_createFromFile("assets/ground1.png", NULL);
    sfTexture *tile2 = sfTexture_createFromFile("assets/ground2.png", NULL);
    sfTexture *tile4 = sfTexture_createFromFile("assets/win.png", NULL);
    sfVector2f scale = {5, 5};

    if (new->type == 1)
        sfSprite_setTexture(new->sprite, tile1, sfFalse);
    if (new->type == 2)
        sfSprite_setTexture(new->sprite, tile2, sfFalse);
    if (new->type == 4) {
        sfSprite_setTexture(new->sprite, tile4, sfFalse);
        new->pos.y += 10;
    }
    sfSprite_setPosition(new->sprite, new->pos);
    sfSprite_setScale(new->sprite, scale);
    return (new);
}

tile **create_tiles(objects *object)
{
    int r = 0;
    int c = 0;
    int i = 0;
    tile **tiles = malloc(sizeof(tile *) * (object->tile_count + 1));

    for (r = 0; object->map[r] != NULL; r += 1) {
        for (c = 0; object->map[r][c] != '\0'; c += 1) {
            if (object->map[r][c] != ' ' && object->map[r][c] != '\n') {
                tiles[i] = malloc(sizeof(tile));
                tiles[i]->type = object->map[r][c] - 48;
                tiles[i]->sprite = sfSprite_create();
                tiles[i]->pos.x = c * 100;
                tiles[i]->pos.y = r * 100;
                tiles[i] = create_tile_sprite(tiles[i]);
                i += 1;
            }
        }
    }
    tiles[object->tile_count] = NULL;
    return (tiles);
}