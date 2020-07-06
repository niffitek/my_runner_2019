/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/game.h"

int display_help(int ac, char **av)
{
    char buffer[500];
    int fd = 0;
    int size = 0;

    buffer[size] = '\0';
    if (ac == 1) {
        fd = open("error", O_RDONLY);
        size = read(fd, buffer, 500);
        write(2, buffer, size);
        return (2);
    }
    if (ac == 2)
        if (av[1][0] == '-' && av[1][1] == 'h') {
            fd = open("help", O_RDONLY);
            size = read(fd, buffer, 500);
            write(1, buffer, size);
            return (1);
        }
    return (0);
}

void move(objects *object)
{
    move_background(object);
    move_midground(object);
    move_map(object);
    player_controller(object);
    return;
}

int game_over(objects *object, int i)
{
    sfRenderWindow_setMouseCursorVisible(object->window, sfTrue);
    while (sfRenderWindow_isOpen(object->window)) {
        while (sfRenderWindow_pollEvent(object->window, &object->event))
            if (game_over_button(object)) {
                return (1);
            }
        sfRenderWindow_clear(object->window, sfBlue);
        set_text(object, 0, score_handling(object));
        if (!i)
            set_text(object, 1, "  GAME OVER");
        else
            set_text(object, 1, "    YOU WIN");
        set_text(object, 2, "Restart");
        set_text(object, 3, "  Exit");
        set_text(object, 4, highscore_handling(object));
        sfRenderWindow_display(object->window);
    }
    return (1);
}

int game(objects *object)
{
    while (sfRenderWindow_isOpen(object->window)) {
        while (sfRenderWindow_pollEvent(object->window, &object->event))
            event_manager(object);
        object->gametime = sfClock_getElapsedTime(object->clock);
        move(object);
        if (win(object))
            if (game_over(object, 1))
                return (0);
        if (collision(object))
            if (game_over(object, 0))
                return (0);
        set_text(object, 0, score_handling(object));
        set_text(object, 4, highscore_handling(object));
        sfRenderWindow_display(object->window);
    }
    return (0);
}

int main(int ac, char **av)
{
    objects *object;
    int error = display_help(ac, av);

    if (error == 2)
        return (84);
    object = build_game(av[1]);
    while (sfRenderWindow_isOpen(object->window) && !error) {
        while (sfRenderWindow_pollEvent(object->window, &object->event))
            if (menu_button(object)) {
                end(object);
                return (0);
            }
        sfRenderWindow_clear(object->window, sfBlue);
        set_text(object, 1, "PIRATE RUNNER");
        set_text(object, 2, "Play");
        set_text(object, 3, "Exit");
        set_text(object, 4, highscore_handling(object));
        sfRenderWindow_display(object->window);
    }
    end(object);
    return (0);
}