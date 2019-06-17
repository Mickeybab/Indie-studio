/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** dig_in_maze
*/

#include "Generator.hpp"

void mark_visited(t_param *p)
{
    p->maze[p->y][p->x] = '*';
}

void mark_dead_end(t_param *p)
{
    p->maze[p->y][p->x] = 'o';
}

t_res valid_neighbour(t_param *p)
{
    if (p->valid[0] != NONE)
        return (TRUE);
    return (FALSE);
}

int go_there(t_param *p)
{
    if (p->choice == UP)
        p->y = p->y - 1;
    if (p->choice == RIGHT)
        p->x = p->x + 1;
    if (p->choice == DOWN)
        p->y = p->y + 1;
    if (p->choice == LEFT)
        p->x = p->x - 1;
    if (p->choice == NONE)
        return (0);
    return (1);
}

int dig_in_maze(t_param *p)
{
    int visited;
    int dead_end;

    visited = 1;
    dead_end = 0;
    while (visited > dead_end)
    {
        mark_visited(p);
        get_valid_neighbour(p);
        if (valid_neighbour(p) == TRUE)
        {
            visited++;
            choose_direction(p);
            go_there(p);
        }
        else
        {
            dead_end++;
            mark_dead_end(p);
            get_valid_visited(p);
            choose_direction(p);
            go_there(p);
        }
    }
    return (0);
}
