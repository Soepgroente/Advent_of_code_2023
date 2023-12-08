#ifndef DAY8_H
# define DAY8_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <limits.h>
#include <math.h>

#define LEFT false
#define RIGHT true

typedef struct s_map
{
	int				loc;
	int				left;
	int				right;
	struct s_map*	nx;
	struct s_map*	first;
}	t_map;

char		**ft_split(const char *s, char c);
void		silver_day8(char** input);
void		gold_day8(char** input);
uint64_t	advtoi(char* str);
int			advatoi2(char** str);

t_map*		new_node(int location, int left, int right, t_map* map);
t_map*		map_last(t_map* map);
void		map_add_back(t_map** map, t_map* node);
void		print_map(t_map* map);
t_map*		find_in_map(t_map* map, int location);
void		print_node(t_map* map);

uint64_t	find_greatest_common_factor(uint64_t nums[]);
int			next_prime(int prime);
int			ft_sqrt(uint64_t num);

#endif