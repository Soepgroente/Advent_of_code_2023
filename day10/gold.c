#include "day10.h"

int size;

static t_map*	move_map(t_map* map, t_token* prev)
{
	t_token	move;
	t_token	options[4][6] = {
		{BLOCKED, NORTH, BLOCKED, SOUTH, BLOCKED, EAST},
		{NORTH, BLOCKED, SOUTH, BLOCKED, BLOCKED, WEST},
		{BLOCKED, BLOCKED, EAST, WEST, NORTH, BLOCKED},
		{EAST, WEST, BLOCKED, BLOCKED, SOUTH, BLOCKED}
	};
	move = options[*prev][map->symbol];
	*prev = move;
	if (move == NORTH)
		map = map->up;
	else if (move == SOUTH)
		map = map->down;
	else if (move == WEST)
		map = map->pv;
	else if (move == EAST)
		map = map->nx;
	else
	{
		puts("Whoops");
		exit(EXIT_FAILURE);
	}
	return (map);
}

static int	count_nest_area(t_map* map)
{
	t_map*	tmp;
	int count = 0;

	tmp = map;
	while (map != NULL)
	{
		while (map != NULL)
		{
			while (map->part_of_loop == true && map->nx != NULL)
				map = map->nx;
			if (count_pipes(map->pv) == true)
			{
				count++;
				map->inside_loop = true;
				map->symbolchar = '$';
			}
			map = map->nx;
		}
		tmp = tmp->down;
		map = tmp;
	}
	return (count);
}

static void	mark_loop(t_map* map)
{
	t_token prev;
	
	map->part_of_loop = true;
	map = map->pv;
	prev = WEST;
	while (map->symbol != START)
	{
		map->part_of_loop = true;
		map = move_map(map, &prev);
	}
}

static t_map*	get_start(t_map* map)
{
	t_map* tmp;

	tmp = map;
	while (map != NULL)
	{
		if (map->symbol == START)
			return (map);
		if (map->nx == NULL)
		{
			tmp = tmp->down;
			map = tmp;
		}
		else
			map = map->nx;
	}
	puts("ERROR");
	exit(EXIT_FAILURE);
}

static t_map*	create_map(char** input)
{
	t_map*	map;
	int i = 0;
	int j = 1;

	map = new_node(input[0][0], NULL);
	while (input[i] != NULL)
	{
		while (input[i][j] != '\0')
		{
			map->nx = new_node(input[i][j], map->first);
			map->nx->pv = map;
			map->up = up_node(map);
			map = map->nx;
			j++;
		}
		i++;
		j = 0;
	}
	map = map->first;
	while (map->nx != NULL)
	{
		map->down = down_node(map);
		map = map->nx;
	}
	map = map->first;
	while (map->down != NULL)
	{
		map->pv = NULL;
		map = map->down;
		map->pv->nx = NULL;
	}
	return (map->first);
}

void	gold_day10(char** input)
{
	t_map*	map;
	int 	result;

	size = count_array(input);
	map = create_map(input);
	map = get_start(map);
	mark_loop(map);
	map = map->first;
	result = count_nest_area(map);
	printf("Gold: %d\n", result);
}
