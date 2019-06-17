/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** neighbour2
*/

#include "Generator.hpp"

int nb_visited(int x, int y, t_param *p)
{
    int visited;

    visited = 0;
    if (y != 0)
        if (p->maze[y - 1][x] != 'X')
            visited++;
    if (x != p->width - 1)
        if (p->maze[y][x + 1] != 'X')
            visited++;
    if (y != p->height - 1)
        if (p->maze[y + 1][x] != 'X')
            visited++;
    if (x != 0)
        if (p->maze[y][x - 1] != 'X')
            visited++;
    return (visited);
}

void reset_valid(t_param *p)
{
    p->valid[0] = NONE;
    p->valid[1] = NONE;
    p->valid[2] = NONE;
    p->valid[3] = NONE;
}

void add(t_path path, t_param *p)
{
    int i;

    i = 0;
    while (p->valid[i] != NONE && i <= 3)
    {
        i++;
    }
    p->valid[i] = path;
}

t_res is_unvisited(int x, int y, t_param *p)
{
    if (p->maze[y][x] == 'X')
        return (TRUE);
    return (FALSE);
}
