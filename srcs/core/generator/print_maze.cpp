/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** print_maze
*/

#include "Generator.hpp"

void print_maze(t_param *p)
{
    int j;

    j = 0;
    while (j < p->height - 1)
    {
        std::cout << p->maze[j] << std::endl;
        j++;
    }
    std::cout << p->maze[j] << std::endl;
}
