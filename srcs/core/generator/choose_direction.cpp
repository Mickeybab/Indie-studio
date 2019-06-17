/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** choose_direction
*/

#include "Generator.hpp"

int choose_direction(t_param *p)
{
    int i;

    i = 0;
    while (p->valid[i] != NONE && i <= 3)
    {
        i++;
    }
    if (i == 0)
    {
        p->choice = NONE;
        return (i);
    }
    i = rand() % i;
    p->choice = p->valid[i];
    return (i);
}
