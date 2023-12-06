#include "day5.h"

uint64_t	seeds[20];
t_map*		maps[8];
uint64_t	lowest;

static uint64_t	calc_next_location(t_map* map, uint64_t seed)
{
	while (map != NULL)
	{
		if (map->src <= seed && map->src + map->range > seed)
			return (seed + map->dest - map->src);
		map = map->nx;
	}
	return (seed);
}

static uint64_t	calculate_seed(void)
{
	uint64_t	location = UINT64_MAX;
	uint64_t	seed;
	int i = 0;

	while (i < 20)
	{
		seed = seeds[i];
		for (int x = 0; x < 7; x++)
			seed = calc_next_location(maps[x], seed);
		if (seed < location)
			location = seed;
		i++;
	}
	return (location);
}

static void	parse_input(char** input)
{
	int i = 0;
	t_map	*map;

	while (*input != NULL && isdigit(**input) == false)
		input++;
	while (*input != NULL)
	{
		maps[i] = new_node();
		map = maps[i];
		map->dest = advtoi(&input[0]);
		map->src = advtoi(&input[0]);
		map->range = advtoi(&input[0]);
		input++;
		while (*input != NULL && isdigit(**input) == true)
		{
			map->nx = new_node();
			map = map->nx;
			map->dest = advtoi(&input[0]);
			map->src = advtoi(&input[0]);
			map->range = advtoi(&input[0]);
			input++;
		}
		while (*input != NULL && isdigit(**input) == false)
			input++;
		i++;
	}
}

void	silver_day5(char** input)
{
	int i = 0;

	while (isdigit(**input) == false)
		(*input)++;
	while (i < 20)
	{
		seeds[i] = advtoi(&input[0]);
		while (**input != '\0' && isdigit(**input) == false)
			(*input)++;
		i++;
	}
	parse_input(input);
	printf("Silver: %llu\n", calculate_seed());
	gold_day5();
}