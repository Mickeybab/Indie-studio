/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** neighbour
*/

#include "Generator.hpp"

t_res up_is_valid(t_param *p)
{
    if (p->y == 0)
        return (FALSE);
    if (nb_visited(p->x, p->y - 1, p) == 1 && is_unvisited(p->x, p->y - 1, p) == TRUE)
        return (TRUE);
    return (FALSE);
}

t_res right_is_valid(t_param *p)
{
    if (p->x == p->width - 1)
        return (FALSE);
    if (nb_visited(p->x + 1, p->y, p) == 1 && is_unvisited(p->x + 1, p->y, p) == TRUE)
        return (TRUE);
    return (FALSE);
}

t_res down_is_valid(t_param *p)
{
    if (p->y == p->height - 1)
        return (FALSE);
    if (nb_visited(p->x, p->y + 1, p) == 1 && is_unvisited(p->x, p->y + 1, p) == TRUE)
        return (TRUE);
    return (FALSE);
}

t_res left_is_valid(t_param *p)
{
    if (p->x == 0)
        return (FALSE);
    if (nb_visited(p->x - 1, p->y, p) == 1 && is_unvisited(p->x - 1, p->y, p) == TRUE)
        return (TRUE);
    return (FALSE);
}

void get_valid_neighbour(t_param *p)
{
    reset_valid(p);
    if (up_is_valid(p) == TRUE)
        add(UP, p);
    if (right_is_valid(p) == TRUE)
        add(RIGHT, p);
    if (down_is_valid(p) == TRUE)
        add(DOWN, p);
    if (left_is_valid(p) == TRUE)
        add(LEFT, p);
}
