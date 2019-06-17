/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** clean_maze
*/

#include "Generator.hpp"

void clean_maze(t_param *p)
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
            if (p->maze[j][i] == 'o' || p->maze[j][i] == '*')
                p->maze[j][i] = ' ';
            i++;
        }
        j++;
    }
}
