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

static int	find_loop_length(t_map* map)
{
	int i = 1;
	t_token prev;
	
	map = map->pv;
	prev = WEST;
	while (map->symbol != START)
	{
		map = move_map(map, &prev);
		i++;
	}
	return (i);
}

static t_map*	get_start(t_map* map)
{
	while (map != NULL)
	{
		if (map->symbol == START)
			return (map);
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
	return (map);
}

void	silver_day10(char** input)
{
	t_map*	map;
	int result;

	size = count_array(input);
	map = create_map(input);
	map = get_start(map);
	result = find_loop_length(map);
	printf("Silver: %d\n", result / 2 + result % 2);
}