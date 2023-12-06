#ifndef DAY5_H
# define DAY5_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <limits.h>
#include <math.h>

typedef struct s_map	t_map;

extern uint64_t	seeds[20];
extern t_map*	maps[8];
extern uint64_t	lowest;

struct s_map
{
	uint64_t		dest;
	uint64_t		src;
	uint64_t		range;
	struct s_map	*nx;
};

char		**ft_split(const char *s, char c);
void		silver_day5(char** input);
void		gold_day5(void);
uint64_t	advtoi(char** str);

void		map_add_back(t_map* map, t_map* node);
t_map*		map_last(t_map* map);
t_map*		new_node(void);
void		print_map(t_map* map);

#endif