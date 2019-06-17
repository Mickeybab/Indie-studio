/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** dig_exit
*/

#include "Generator.hpp"

void dig_exit(t_param *p)
{
    int random;

    p->x = p->width - 1;
    p->y = p->height - 1;
    random = rand() % 2;
    while (p->maze[p->y][p->x] != 'o')
    {
        mark_visited(p);
        if (random == 0)
            p->x = p->x - 1;
        else
            p->y = p->y - 1;
    }
}
