/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** get_param
*/

#include "Generator.hpp"

char *get_mazeline(int x)
{
    int i;
    char *line;

    line = static_cast<char*>(malloc(sizeof(char) * (x + 1)));
    if (line == NULL)
        return (NULL);
    i = 0;
    while (i < x)
    {
        line[i] = 'X';
        i++;
    }
    line[x] = '\0';
    return (line);
}

char **get_maze(int x, int y)
{
    int i;
    char **maze;

    maze = static_cast<char**>(malloc(sizeof(char *) * (y + 1)));
    if (maze == NULL)
        return (NULL);
    maze[y] = NULL;
    i = 0;
    while (i < y)
    {
        maze[i] = get_mazeline(x);
        if (maze[i] == NULL)
            return (NULL);
        i++;
    }
    return (maze);
}

t_res get_perfect(int argc, char **argv)
{
    if (argc == 4)
        if (strcmp("perfect", argv[3]) == 0)
            return (YES);
    return (NO);
}

t_param *get_param(int argc, char **argv)
{
    t_param *p;

    srand(time(NULL));
    p = (t_param*)(malloc(sizeof(t_param)));
    if (p == NULL)
        return (NULL);
    p->width = atoi(argv[1]);
    p->height = atoi(argv[2]);
    p->x = 0;
    p->y = 0;
    p->maze = get_maze(p->width, p->height);
    if (p->maze == NULL)
        return (NULL);
    p->perfect = get_perfect(argc, argv);
    return (p);
}