#include "day7.h"

static int	convert_char(char c)
{
	if (isdigit(c) == true)
		return (c - '0' + 100);
	else if (c == 'T')
		return (110);
	else if (c == 'J')
		return (111);
	else if (c == 'Q')
		return (112);
	else if (c == 'K')
		return (113);
	else if (c == 'A')
		return (114);
	else
	{
		puts("MISTAKE");
		exit(EXIT_FAILURE);
	}
}

static uint64_t	assign_total(int cards[5], int rank)
{
	uint64_t hand_value = 0;
	int i = 0;
	uint64_t tmp = 0;

	while (i < 4 && cards[i] == cards[i + 1])
	{
		hand_value += cards[i];
	}
	hand_value += cards[i];
	hand_value *= rank;
	if (rank == TWO_PAIR || rank == FULL_HOUSE)
	{
		while (i < 4 && cards[i] == cards[i + 1])
		{
			tmp += cards[i];
		}
		tmp += cards[i];
		hand_value += tmp * rank / 5;
	}
	while (i < 5)
		hand_value += cards[i];
	return (hand_value);
}

static uint64_t	determine_rank(int* cards[5])
{
	int i; 
	int tmp; 
	int count = 0; 
	int count2;
	int value = 0;
	bool edgecase = false;

	for (i = 0; i < 5; i++)
	{
		count2 = 0;
		tmp = cards[i];
		for (int j = i + 1; j < 5; j++)
		{
			if (cards[j] == tmp)
				count2++;
		}
		if (count2 > 0)
			count = count2;
		if (count == 1)
			edgecase = true;
	}
	if (count == 2 && edgecase == true)
		return (FULL_HOUSE);
	if (count == 0)
		return (HIGH_CARD);
	if (count == 1)
		return (ONE_PAIR);
	if (count == 1 && edgecase == true)
		return (TWO_PAIR);
	if (count == 3)
		return (TRIPS);
	if (count == 4)
		return (QUADS);
	if (count == 5)
		return (YAHTZEE);
}

static t_hand	assign_value(char* str)
{
	int*	ordered_hand;
	int		rank;
	t_hand 	hand;

	for (int i = 0; i < 5; i++)
		hand.cards[i] = convert_char(str[i]);
	hand.multiplier = advtoi(&str[6]);
	ordered_hand = sort_hand(hand.cards);
	for (int i = 0; i < 5; i++)
		hand.cards[i] = ordered_hand[i];
	free(ordered_hand);
	hand.rank = determine_rank(hand.cards);
	hand.value = assign_total(hand.cards, rank);
	return (hand);
}

static int find_highest(t_hand* list)
{
	int highest = 0; int pos = 0;

	for (int i = 0; i < 1000; i++)
	{
		if (list[i].value > highest)
		{
			highest = list[i].value;
			pos = i;
		}
	}
	return (pos);
}

static uint64_t	sort_result(t_hand* list)
{
	t_hand* result;
	int pos;

	result = calloc(1000, sizeof(t_hand));
	for (int i = 0; i < 1000; i++)
	{
		pos = find_highest(list);
		result[i].value = list[pos].value * list[pos].multiplier;
		list[pos].value = 0;
	}
	
}

void	silver_day7(char** input)
{
	t_hand*	hands;
	t_hand*	result;

	hands = calloc(1000, sizeof(t_hand));
	for (int i = 0; input[i] != NULL; i++)
		hands[i] = assign_value(input[i]);
	result = sort_result(hands);
	printf("Silver: %d\n", result);
}