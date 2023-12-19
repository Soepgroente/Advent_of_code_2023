#ifndef DAY12_H
# define DAY12_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <limits.h>
#include <math.h>

typedef enum s_token
{
	QUESTIONMARK,
	WORKS,
	BROKEN
}	t_token;

typedef struct	s_map
{
	t_token			status;
	int				amount;
	struct s_map*	nx;
	struct s_map*	pv;
}	t_map;

/*	Lists	*/

void		clear_list(t_map** list);
t_map*		new_node(char symbol, int amount);
t_map*		map_last(t_map* map);
void		map_add_back(t_map** map, t_map* node);
void		print_map(t_map* map);

/*	Program	*/

void		silver_day12(char** input);
void		gold_day12(char** input);

/*	Utils	*/

char		**ft_split(const char *s, char c);
uint64_t	advtoi(char** str);
int			count_array(char** array);
void		print_2d(char** array);
void		printeger_2d(int** array, int xs, int ys);

#endif