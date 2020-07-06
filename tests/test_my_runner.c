/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include <criterion/criterion.h>
#include "../include/game.h"

Test(display_help, error_management)
{
    int output = display_help(1, "");
    cr_assert_eq(output, 84);
}