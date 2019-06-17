/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** check_error
*/

#include "Generator.hpp"

t_res isnum(char c)
{
    if (c >= '0' && c <= '9')
        return (TRUE);
    return (FALSE);
}

t_res isnb(char *nb)
{
    int i;

    i = 0;
    while (nb[i] != '\0')
    {
        if (isnum(nb[i]) == FALSE)
            return (FALSE);
        i = i + 1;
    }
    return (TRUE);

}

t_res check_error(int argc, char **argv)
{
    if (argc > 4 || argc < 3){
        return (ERROR);
    }
    if (isnb(argv[1]) == FALSE || isnb(argv[2]) == FALSE) {
        return (ERROR);
    }
    if (atoi(argv[1]) <= 0 || atoi(argv[2]) <= 0) {
        return (ERROR);
    }
    return (SUCCESS);
}