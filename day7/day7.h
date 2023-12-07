#ifndef DAY7_H
# define DAY7_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <limits.h>
#include <math.h>

typedef enum s_ranks
{
	NOTHING,
	HIGH_CARD,
	ONE_PAIR,
	TWO_PAIR,
	TRIPS,
	FULL_HOUSE,
	QUADS,
	YAHTZEE
}	t_ranks;

typedef struct s_hand
{
	int			cards[5];
	uint64_t	value;
	int			rank;
	uint64_t	multiplier;
}	t_hand;

char		**ft_split(const char *s, char c);
void		silver_day7(char** input);
void		gold_day7(char** input);
uint64_t	advtoi(char* str);

#endif