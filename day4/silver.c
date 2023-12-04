#include "day4.h"

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
	int tmp = 0; int i; int count = 0;

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
	if (count == 0)
		return (0);
	return ((uint64_t)pow(2, count - 1));
}

static uint64_t	add_up_scratchcards(char** input)
{
	uint64_t	total = 0;
	int*	winners;
	int i = 0;

	winners = calloc(10, sizeof(int));
	while (*input != NULL)
	{
		while (**input != ':')
			(*input)++;
		(*input)++;
		while (**input != '\0' && **input != '|')
		{
			if (isdigit(**input) == true)
			{
				winners[i] = (int)(get_number(input));
				i++;
			}
			while (**input != '\0' && isdigit(**input) == false && **input != '|')
				(*input)++;
		}
		total += winning_points(*input, winners);
		input++;
		i = 0;
	}
	return (total);
}

void	silver_day4(char** input)
{
	printf("Silver: %llu\n", add_up_scratchcards(input));
}