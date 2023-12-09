#include "day5.h"

static uint64_t	calc_next_location(t_map* map, uint64_t seed)
{
	static int x = 0; static int count = 0;

	x++;
	if (x % 1000000 == 0)
	{
		x = 0;
		count++;
		printf("%d mill\n", count);
	}
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
	uint64_t	seed2;
	uint64_t	seedsum;
	int i = 0;

	while (i < 20)
	{
		seed = seeds[i];
		seed2 = seeds[i + 1];
		for (uint64_t y = 0; y < seed2; y++)
		{
			seedsum = seed + y;
			for (int x = 0; x < 7; x++)
				seedsum = calc_next_location(maps[x], seedsum);
			if (seedsum < location)
				location = seedsum;
		}
		i += 2;
		printf("Hi! I've made progress. i is: %d\n", i);
	}
	return (location);
}

void	gold_day5(void)
{
	printf("Gold: %llu\n", calculate_seed());
}