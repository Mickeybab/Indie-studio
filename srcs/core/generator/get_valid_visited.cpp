/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** get_valid_visited
*/

#include "Generator.hpp"

void get_valid_visited(t_param *p)
{
    reset_valid(p);
    if (p->y != 0)
        if (p->maze[p->y - 1][p->x] == '*')
            add(UP, p);
    if (p->x != p->width - 1)
        if (p->maze[p->y][p->x + 1] == '*')
            add(RIGHT, p);
    if (p->y != p->height - 1)
        if (p->maze[p->y + 1][p->x] == '*')
            add(DOWN, p);
    if (p->x != 0)
        if (p->maze[p->y][p->x - 1] == '*')
            add(LEFT, p);
}
