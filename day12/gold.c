#include "day12.h"

static int**	set_coordinates(int** map)
{

}

static uint64_t	calc_configs(char* input)
{
	
}

void	gold_day12(char** input)
{
	uint64_t result = 0;

	for (int i = 0; input[i] != NULL; i++)
		result += calc_configs(input[i]);
	printf("Gold: %llu\n", result);
}