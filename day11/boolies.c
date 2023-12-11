#include "day10.h"

bool	count_pipes(t_map* map)
{
	int i = 0;
	bool	up;

	while (map != NULL && map->pv != NULL)
	{
		while (map != NULL && map->part_of_loop == true && map->symbol == VERTICAL)
		{
			i++;
			map = map->pv;
		}
		if (map != NULL && map->part_of_loop == true)
		{
			if (map->symbol == NORTH_WEST)
				up = true;
			else if (map->symbol == SOUTH_WEST)
				up = false;
			while (map->part_of_loop == true && map->symbol == HORIZONTAL)
				map = map->pv;
			if (up == false && map->symbol == NORTH_EAST)
				i++;
			else if (up == true && map->symbol == SOUTH_EAST)
				i++;
		}
		while (map != NULL && map->part_of_loop == true && map->symbol == VERTICAL)
		{
			i++;
			map = map->pv;
		}
		if (map != NULL)
			map = map->pv;
	}
	if (i % 2 == 0)
		return (false);
	return (true);
}
