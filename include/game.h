/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** functions
*/

#ifndef MUL_MY_HUNTER_2019_GAME_H
#define MUL_MY_HUNTER_2019_GAME_H

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include "../include/structs.h"

int event_manager(objects *object);
int is_on_ground(objects *object);
double do_jump(objects *object);
int menu_button(objects *object);
int game_over_button(objects *object);

int game(objects *object);

void move_background(objects *object);
void move_midground(objects *object);
void move_map(objects *object);

int count_map(char *map);
char **map_to_array(char *buffer);

player_t create_player(void);
void player_controller(objects *object);

objects *build_game(char *av);
int restart(objects *object);
void end(objects *object);
sfSprite *create_background(void);
sfSprite *create_midground(void);
sfRenderWindow *create_window(void);
tile **create_tiles(objects *object);
objects *build_texts(objects *object);
int display_help(int ac, char **av);

void set_text(objects *object, int i, char *str);
char *score_handling(objects *object);
char *highscore_handling(objects *object);
int get_highscore(int score);

int collision(objects *object);
int win(objects *object);

int display_help(int ac, char **av);

#endif //MUL_MY_HUNTER_2019_GAME_H
