#include "day8.h"

uint64_t	result;
int			len;
int			size;

void	find_A_nodes(t_map* map, int* array[])
{
	int i = 0;

	while (map != NULL)
	{
		if (map->loc % 100 == 'A')
		{
			(*array)[i] = map->loc;
			i++;
		}
		map = map->nx;
	}
}

static void	find_xxA(t_map* map)
{
	while (map != NULL)
	{
		if (map->loc % 100 == 'A')
			size++;
		map = map->nx;
	}
}

static bool	all_on_xxZ(int* array)
{
	int i = 0;
	static uint64_t res[6];

	while (i < size)
	{
		if (array[i] % 100 == 'Z')
		{
			if (res[i] == 0)
				res[i] = result;
			for (i = 0; i < 6; i++)
				if (res[i] == 0)
					return (false);
			uint64_t gcd = find_greatest_common_factor(res);
			for (i = 1; i < 6; i++)
				res[i] /= gcd;
			uint64_t total = 1;
			for (i = 0; i < 6; i++)
				total *= res[i];
			printf("Gold: %llu\n", total);
			exit(0);
		}
		i++;
	}
	return (false);
	// return (true);
}

static void	count_path(t_map* map, bool* directions)
{
	int i; int j; int* array;

	array = calloc(size, sizeof(int));
	find_A_nodes(map, &array);
	while (1)
	{
		i = 0;
		while (i < len)
		{
			j = 0;
			while (j < size)
			{
				map = find_in_map(map->first, array[j]);
				if (directions[i] == LEFT)
					map = find_in_map(map->first, map->left);
				else if (directions[i] == RIGHT)
					map = find_in_map(map->first, map->right);
				array[j] = map->loc;
				j++;
			}
			result++;
			if (all_on_xxZ(array) == true)
				return ;
			i++;
		}
	}
}

void	gold_day8(char** input)
{
	int i;
	int location; int left; int right;
	bool*	directions;
	t_map*	map;

	map = NULL;
	result = 0;
	size = 0;
	len = strlen(*input);
	directions = calloc(len, sizeof(bool));
	for (i = 0; i < len; i++)
	{
		if (input[0][i] == 'L')
			directions[i] = LEFT;
		else if (input[0][i] == 'R')
			directions[i] = RIGHT;
	}
	input++;
	while (*input != NULL)
	{
		location = advatoi2(input);
		left = advatoi2(input);
		right = advatoi2(input);
		map_add_back(&map, new_node(location, left, right, map));
		input++;
	}
	map->first = map;
	find_xxA(map);
	count_path(map, directions);
	printf("Gold result: %llu\n", result);
}