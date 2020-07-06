/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/game.h"

ui_text create_text(int x, int y, int size)
{
    ui_text score;
    score.text = sfText_create();
    score.font = sfFont_createFromFile("assets/font.ttf");
    score.pos.x = x;
    score.pos.y = y;

    sfText_setFont(score.text, score.font);
    sfText_setCharacterSize(score.text, size);
    sfText_setPosition(score.text, score.pos);
    return (score);
}

objects *build_texts(objects *object)
{
    object->score = 0;
    object->highscore = get_highscore(object->score);
    object->score_texts = malloc(sizeof(char) * 11);
    object->highscore_texts = malloc(sizeof(char) * 15);
    object->texts[0] = create_text(10, 0, 70);
    object->texts[1] = create_text(90, 50, 300);
    object->texts[2] = create_text(850, 600, 80);
    object->texts[3] = create_text(850, 700, 80);
    object->texts[4] = create_text(10, 40, 70);
    sfMusic_setLoop(object->music, 1);
    sfMusic_play(object->music);
    return (object);
}

void set_text(objects *object, int i, char *str)
{
    sfText_setString(object->texts[i].text, str);
    sfRenderWindow_drawText(object->window, object->texts[i].text, NULL);
}

char *highscore_handling(objects *object)
{
    object->highscore = get_highscore(object->score);
    object->highscore_texts[0] = 'H';
    object->highscore_texts[1] = 'i';
    object->highscore_texts[2] = 'g';
    object->highscore_texts[3] = 'h';
    object->highscore_texts[4] = 's';
    object->highscore_texts[5] = 'c';
    object->highscore_texts[6] = 'o';
    object->highscore_texts[7] = 'r';
    object->highscore_texts[8] = 'e';
    object->highscore_texts[9] = ':';
    object->highscore_texts[10] = ' ';
    object->highscore_texts[11] = object->highscore / 100 + 48;
    object->highscore_texts[12] = object->highscore / 10 % 10 + 48;
    object->highscore_texts[13] = object->highscore % 10 + 48;
    object->highscore_texts[14] = '\0';
    return (object->highscore_texts);
}

char *score_handling(objects *object)
{
    object->score = object->gametime.microseconds / 100000.0;

    if (object->score < 0)
        object->score = 0;
    object->score_texts[0] = 'S';
    object->score_texts[1] = 'c';
    object->score_texts[2] = 'o';
    object->score_texts[3] = 'r';
    object->score_texts[4] = 'e';
    object->score_texts[5] = ':';
    object->score_texts[6] = ' ';
    if (object->score > 999)
        object->score = 999;
    object->score_texts[7] = object->score / 100 + 48;
    object->score_texts[8] = object->score / 10 % 10 + 48;
    object->score_texts[9] = object->score % 10 + 48;
    object->score_texts[10] = '\0';
    return (object->score_texts);
}