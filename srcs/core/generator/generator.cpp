/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** generator
*/

#include "Generator.hpp"

char **error()
{
    std::cerr << "Error, bad arguments" << std::endl;
    return (NULL);
}

char **error_in_maze()
{
    std::cerr << "Error, seems there is malloc error in maze ..."
    << std::endl;
    return (NULL);
}

char **generator(int nbarg, char *x, char *y, char *flag)
{
    t_param     *p;
    char        **maze;
    char *argv[4] = {x, x, y, flag};

    if (check_error(nbarg, argv) == ERROR)
        return (error());
    p = get_param(nbarg, argv);
    if (p == NULL)
        return (error());
    dig_in_maze(p);
    if (p->perfect == NO)
        break_some_walls(p);
    dig_exit(p);
    clean_maze(p);
    maze = p->maze;
    free(p);
    return (maze);
}