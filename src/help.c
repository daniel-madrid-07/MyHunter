/*
** EPITECH PROJECT, 2025
** Graphical_Programming
** File description:
** Help functions
*/

#include "../include/my.h"

void print_help_rules(void)
{
    my_printf("HOW TO PLAY:\n");
    my_printf("    1. Click the START button to begin\n");
    my_printf("    2. Wait for the countdown to finish\n");
    my_printf("    3. Shoot the Kirbys by clicking on them\n");
    my_printf("    4. Each successful hit increases your score\n");
    my_printf("    5. You have 3 bullets - missing costs you a bullet\n\n");
    my_printf("WIN CONDITION:\n");
    my_printf("    - Shoot as many Kirbys as possible!\n");
    my_printf("    - The game gets faster as you progress\n\n");
    my_printf("LOSE CONDITION:\n");
    my_printf("    - Missing 3 shots (running out of bullets)\n\n");
    my_printf("CONTROLS:\n");
    my_printf("    - Left Click: Shoot\n");
    my_printf("    - ESC: Pause/Exit menu\n\n");
}

void print_help(void)
{
    my_printf("MY_HUNTER - A Kirby Shooting Game\n\n");
    my_printf("USAGE:\n");
    my_printf("    ./my_hunter\n");
    my_printf("    ./my_hunter -h (for help)\n\n");
    my_printf("DESCRIPTION:\n");
    my_printf("    My Hunter is a shooting game where you must click on ");
    my_printf("flying Kirbys\n");
    my_printf("    before they escape across the screen.\n\n");
    print_help_rules();
}

static int is_help_arg(char *arg)
{
    return (arg[0] == '-' && arg[1] == 'h' && arg[2] == '\0');
}

int check_args(int ac, char **av)
{
    if (ac != 2)
        return 0;
    if (is_help_arg(av[1]) == 0)
        return 0;
    print_help();
    return 1;
}
