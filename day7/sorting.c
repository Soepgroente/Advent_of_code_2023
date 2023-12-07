#include "day7.h"

/* static void ft_swap(int* x, int* y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

static void	shove_pairs_ahead(int* hand)
{
	int	tmp[5]; int i;

	for (i = 0; i < 5; i++)
		tmp[i] = hand[i];
	for (i = 0; i < 5; i++)
	{
		if (is_quads(hand, hand[i]) == true)
			tmp[i] = hand[i] * 1000;
		else if (is_trips(hand, hand[i]) == true)
			tmp[i] = hand[i] * 100;
		else if (is_pair(hand, hand[i]) == true)
			tmp[i] = hand[i] * 10;
	}
	for (i = 0; i < 5; i++)
		hand[i] = tmp[i];
}

int*	sort_hand(int* cards)
{
	int* ordered_hand;

	ordered_hand = calloc(5, sizeof(int));
	for (int i = 0; i < 5; i++)
		ordered_hand[i] = cards[i];
	shove_pairs_ahead(ordered_hand);
	while (is_sorted(ordered_hand) == false)
	{
		for (int i = 0; i < 4; i++)
			if (ordered_hand[i] < ordered_hand[i + 1])
				ft_swap(&ordered_hand[i], &ordered_hand[i + 1]);
	}
	return (ordered_hand);
} */

void	print_hand(int* hand)
{
	for (int i = 0; i < 5; i++)
	{
		if (hand[i] == 10)
			printf("%c ", 'T');
		if (hand[i] == 11)
			printf("%c ", 'J');
		if (hand[i] == 12)
			printf("%c ", 'Q');
		if (hand[i] == 13)
			printf("%c ", 'K');
		if (hand[i] == 14)
			printf("%c ", 'A');
		if (hand[i] < 10)
			printf("%d ", hand[i]);
	}
	puts("");
}