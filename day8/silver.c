#include "day8.h"

uint64_t	result;
int			len;

void	count_path(t_map* map, bool* directions)
{
	int i;

	while (1)
	{
		i = 0;
		while (i < len)
		{
			if (directions[i] == LEFT)
			{
				map = find_in_map(map->first, map->left);
			}
			else if (directions[i] == RIGHT)
			{
				map = find_in_map(map->first, map->right);
			}
			result++;
			if (map->loc == 909090)
				return ;
			i++;
		}
	}
}

void	silver_day8(char** input)
{
	int i;
	int location; int left; int right;
	bool*	directions;
	t_map*	map;

	map = NULL;
	result = 0;
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
	map = find_in_map(map, 656565);
	count_path(map, directions);
	printf("Silver: %llu\n", result);
}