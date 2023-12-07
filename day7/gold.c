#include "day7.h"

int size;

static int	convert_char(char c)
{
	if (isdigit(c) == true)
		return (c - '0');
	else if (c == 'T')
		return (10);
	else if (c == 'J')
		return (1);
	else if (c == 'Q')
		return (12);
	else if (c == 'K')
		return (13);
	else if (c == 'A')
		return (14);
	else
	{
		puts("MISTAKE");
		exit(EXIT_FAILURE);
	}
}

static uint64_t	determine_rank(int* cards)
{
	int i = 0; int j = 0;
	int tmp[5] = {0, 0, 0, 0, 0};
	int count = 0;
	int res[2] = {0, 0};
	int jokers = 0;

	for (i = 0; i < 5; i++)
		if (cards[i] == 1)
			jokers++;
	for (i = 0; i < 5; i++)
	{
		if (cards[i] > 1)
			tmp[i] = cards[i];
	}
	for (i = 0; i < 5; i++)
	{
		count = 0;
		for (j = 0; j < 5; j++)
		{
			if (cards[i] == tmp[j])
			{
				count++;
				tmp[j] = 0;
			}
		}
		if (count > res[0])
		{
			res[1] = res[0];
			res[0] = count;
		}
		else if (count > res[1])
			res[1] = count;
	}
	res[0] += jokers;
	if (res[0] == 1)
		return (HIGH_CARD);
	if (res[0] == 2 && res[1] == 2)
		return (TWO_PAIR);
	if (res[0] == 2)
		return (ONE_PAIR);
	if (res[0] == 3 && res[1] == 2)
		return (FULL_HOUSE);
	if (res[0] == 3)
		return (TRIPS);
	if (res[0] == 4)
		return (QUADS);
	if (res[0] == 5)
		return (YAHTZEE);
	return (puts("ERROR"), 0);
}

static t_hand	assign_value(char* str)
{
	t_hand 	hand;

	for (int i = 0; i < 5; i++)
		hand.cards[i] = convert_char(str[i]);
	hand.multiplier = advtoi(&str[5]);
	hand.rank = determine_rank(hand.cards);
	return (hand);
}

static int find_highest(t_hand* list, t_rank rank)
{
	int prev[5] = {0, 0, 0, 0, 0};
	int pos = -1; int i = 0; int j;

	while (i < size)
	{
		j = 0;
		if (list[i].cards[0] >= prev[0] && list[i].rank == rank)
		{
			if (prev[0] == list[i].cards[0])
			{
				while (j < 5 && list[i].cards[j] == prev[j])
					j++;
				if (j < 5 && list[i].cards[j] > prev[j])
				{
					for (int x = 0; x < 5; x++)
						prev[x] = list[i].cards[x];
					pos = i;
				}				
			}
			else
			{
				for (int x = 0; x < 5; x++)
					prev[x] = list[i].cards[x];
				pos = i;
			}
		}
		i++;
	}
	if (pos == -1)
		return (-1);
	list[pos].rank = INVALID;
	return (pos);
}

static uint64_t	sort_result(t_hand* list, t_rank rank)
{
	uint64_t result = 0;
	int pos;
	int i = 0;

	while (rank > 0)
	{
		while (1)
		{
			pos = find_highest(list, rank);
			if (pos == -1)
				break ;
			result += (size - i) * list[pos].multiplier;
			i++;
		}
		rank -= 1;
	}
	return (result);
}

void	gold_day7(char** input)
{
	t_hand*		hands;
	uint64_t	result;
	int i = 0;

	while (input[i] != NULL)
	{
		i++;
	}
	size = i;
	hands = calloc(size, sizeof(t_hand));
	for (i = 0; input[i] != NULL; i++)
	{
		hands[i] = assign_value(input[i]);
	}
	result = sort_result(hands, YAHTZEE);
	free(hands);
	printf("Gold: %llu\n", result);
}