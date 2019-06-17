/*
** EPITECH PROJECT, 2019
** indie-studio
** File description:
** generator
*/

#ifndef GENERATOR_H_
# define GENERATOR_H_

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>

#define MIN(x, y)       ((x) < (y) ? (x) : (y))
#define MAX(x, y)       ((x) > (y) ? (x) : (y))

typedef enum	e_res
  {
    FALSE = -1,
    ERROR = -1,
    FAILURE = -1,
    NO = -1,
    SUCCESS = 0,
    TRUE = 0,
    YES = 0
  }		t_res;

typedef	enum	e_path
  {
    UP, RIGHT, DOWN, LEFT, NONE
  }		t_path;

typedef	struct		s_param
{
  int			width;
  int			height;
  int			x;
  int			y;
  char			**maze;
  t_path		valid[4];
  t_path		choice;
  t_res			perfect;
}			t_param;

char **error();
char **error_in_maze();
char **generator(int nbarg, char *x, char*y, char *flag);

t_res           isnum(char c);
t_res           isnb(char *nb);
t_res           check_error(int argc, char **argv);

char		*get_mazeline(int x);
char            **get_maze(int x, int y);
t_res           get_perfect(int argc, char **argv);
t_param         *get_param(int argc, char **argv);

void            mark_visited(t_param *p);
void            mark_dead_end(t_param *p);
t_res           valid_neighbour(t_param *p);
int             go_there(t_param *p);
int             dig_in_maze(t_param *p);

void            get_valid_visited(t_param *p);

t_res           up_is_valid(t_param *p);
t_res           right_is_valid(t_param *p);
t_res           down_is_valid(t_param *p);
t_res           left_is_valid(t_param *p);
void            get_valid_neighbour(t_param *p);

int             nb_visited(int x, int y, t_param *p);
void            reset_valid(t_param *p);
void            add(t_path path, t_param *p);
t_res           is_unvisited(int x, int y, t_param *p);

int            choose_direction(t_param *p);

void            clean_maze(t_param *p);

void            break_some_walls(t_param *p);

void		print_maze(t_param *p);

void            dig_exit(t_param *p);

#endif