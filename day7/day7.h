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
	INVALID,
	HIGH_CARD,
	ONE_PAIR,
	TWO_PAIR,
	TRIPS,
	FULL_HOUSE,
	QUADS,
	YAHTZEE
}	t_rank;

typedef struct s_hand
{
	int			cards[5];
	t_rank		rank;
	uint64_t	multiplier;
}	t_hand;

char		**ft_split(const char *s, char c);
void		silver_day7(char** input);
void		gold_day7(char** input);
uint64_t	advtoi(char* str);

bool		is_sorted(int* hand);
int*		sort_hand(int* cards);
bool		is_pair(int* hand, int num);
bool		is_trips(int* hand, int num);
bool		is_quads(int* hand, int num);
bool		is_another_pair(int* hand, int pos);
uint64_t	add_all_cards(int* hand);
void		print_hand(int* hand);

#endif