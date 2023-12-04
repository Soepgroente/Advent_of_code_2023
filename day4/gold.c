#include "day4.h"

int size;

static uint64_t	get_number(char** str)
{
	uint64_t num = 0;

	while (**str != '\0' && isdigit(**str) == true)
	{
		num *= 10;
		num += **str - '0';
		(*str)++;
	}
	return (num);
}

static uint64_t	winning_points(char* input, int* winners)
{
	int tmp = 0; int i; uint64_t count = 0;

	while (*input != '\0')
	{
		i = 0;
		if (isdigit(*input) == true)
		{
			tmp = get_number(&input);
			while (i < 10)
			{
				if (tmp == winners[i])
					count++;
				i++;
			}
		}
		if (*input != '\0')
			input++;
	}
	return (count);
}

static uint64_t	add_up_scratchcard(char* input)
{
	uint64_t	total = 0; int i = 0;
	int*	winners;

	winners = calloc(10, sizeof(int));
	while (*input != ':')
		input++;
	input++;
	while (*input != '\0' && *input != '|')
	{
		if (isdigit(*input) == true)
		{
			winners[i] = (int)(get_number(&input));
			i++;
		}
		while (*input != '\0' && isdigit(*input) == false && *input != '|')
			input++;
	}
	total = winning_points(input, winners);
	free(winners);
	return (total);
}

static void	add_copies(uint64_t* card_array2, int i, int val)
{
	int x = 0;
	int copies;

	if (i == size)
		return ;
	copies = card_array2[i];
	i++;
	while (x < val && i < size)
	{
		card_array2[i] += copies;
		i++;
		x++;
	}
}

static uint64_t	add_up_cards(char** input)
{
	int i = 0;
	uint64_t 	total = 0;
	uint64_t	tmp = 0;
	uint64_t*	card_array;
	uint64_t*	card_array2;

	card_array = calloc(size, sizeof(uint64_t));
	card_array2 = calloc(size, sizeof(uint64_t));
	for (int x = 0; x < size; x++)
		card_array2[x] = 1;
	while (i < size)
	{
		card_array[i] = add_up_scratchcard(input[i]);
		i++;
	}
	i = 0;
	while (i < size)
	{
		add_copies(card_array2, i, card_array[i]);
		i++;
	}
	for (int x = 0; x < size; x++)
		tmp += card_array[x];
	for (int y = 0; y < size; y++)
		total += card_array2[y];
	free(card_array);
	free(card_array2);
	return (total);
}

void	gold_day4(char** input)
{
	int i = 0;
	while (input[i] != NULL)
		i++;
	size = i;
	printf("gold day 4: %llu\n", add_up_cards(input));
}
