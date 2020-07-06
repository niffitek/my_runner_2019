/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/game.h"

void end(objects *object)
{
    sfSprite_destroy(object->background);
    sfSprite_destroy(object->background2);
    sfSprite_destroy(object->midground);
    sfSprite_destroy(object->midground2);
    sfSprite_destroy(object->player.sprite);
    for (int i = 0; object->tiles[i]; i += 1) {
        sfSprite_destroy(object->tiles[i]->sprite);
        free(object->tiles[i]);
    }
    free(object->score_texts);
    sfRenderWindow_destroy(object->window);
    sfClock_destroy(object->clock);
    sfMusic_destroy(object->music);
    sfMusic_destroy(object->sound);
    free(object);
}

int restart(objects *object)
{
    sfVector2f pos_player = {100, 810};
    sfVector2f og = {0, 0};
    sfVector2f pos = {1920, 0};

    for (int i = 0; object->tiles[i]; i += 1)
        sfSprite_setPosition(object->tiles[i]->sprite, object->tiles[i]->pos);
    sfSprite_setPosition(object->player.sprite, pos_player);
    sfRenderWindow_setMouseCursorVisible(object->window, sfFalse);
    sfSprite_setPosition(object->background, og);
    sfSprite_setPosition(object->midground, og);
    sfSprite_setPosition(object->background2, pos);
    sfSprite_setPosition(object->midground2, pos);
    object->gametime = sfClock_restart(object->clock);
    object->score = 0;
    object->player.tmptime = 0;
    if (!game(object))
        return (1);
    return (0);
}

int get_highscore(int score)
{
    char buffer[4];
    FILE *fp;
    int fd = open("highscore", O_RDONLY);
    int size = read(fd, buffer, 4);
    int highscore = 0;
    char str[4];

    highscore += (buffer[0] - 48) * 100;
    highscore += (buffer[1] - 48) * 10;
    highscore += (buffer[2] - 48);
    if (score >= highscore) {
        highscore = score;
        str[0] = highscore / 100 + 48;
        str[1] = highscore / 10 % 10 + 48;
        str[2] = highscore % 10 + 48;
        str[3] = '\0';
        fp = fopen ("highscore", "w");
        fwrite(str, 1, sizeof(str), fp);
        fclose(fp);
    }
    return (highscore);
}