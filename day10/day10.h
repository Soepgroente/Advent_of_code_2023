#ifndef day10_H
# define day10_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <limits.h>
#include <math.h>

extern int size;

typedef enum s_token	t_token;

enum s_token
{
	NORTH_EAST,
	NORTH_WEST,
	SOUTH_EAST,
	SOUTH_WEST,
	VERTICAL,
	HORIZONTAL,
	GROUND,
	START,
	BLOCKED,
	EAST = 0,
	WEST = 1,
	NORTH = 2,
	SOUTH = 3,
};

typedef struct s_map
{
	t_token			symbol;
	char			symbolchar;
	bool			part_of_loop;
	bool			inside_loop;
	struct s_map*	up;
	struct s_map*	pv;
	struct s_map*	nx;
	struct s_map*	down;
	struct s_map*	first;
}	t_map;

/*	Program	*/
void		silver_day10(char** input);
void		gold_day10(char** input);

/*	Utils	*/

char		**ft_split(const char *s, char c);
uint64_t	advtoi(char* str);
int			count_array(char** array);
void		print_2d(char** array);
bool		count_pipes(t_map* map);

/*	Lists	*/

t_map*		down_node(t_map* map);
t_map*		up_node(t_map* map);
t_map*		new_node(char symbol, t_map* map);
t_map*		map_last(t_map* map);
void		map_add_back(t_map** map, t_map* node);
void		print_map(t_map* map);

#endif