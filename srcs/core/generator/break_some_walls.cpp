/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** break_some_walls
*/

#include "Generator.hpp"

void break_some_walls(t_param *p)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (p->maze[j] != NULL)
    {
        i = 0;
        while (p->maze[j][i] != '\0')
        {
            if (p->maze[j][i] == 'X' && rand() % 3 == 0)
                p->maze[j][i] = '*';
            i++;
        }
        j++;
    }
}