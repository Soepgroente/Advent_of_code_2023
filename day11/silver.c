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

static void	input_stars(char** input)
{
	
}

static int**	create_map(char** input)
{
	int**	map;
	int 	galaxy = 1;

	size = count_array(input);
	map = calloc(size, sizeof(int*));
	if (map == NULL)
		exit(EXIT_FAILURE);
	for (int i = 0; i < size; i++)
	{
		map[i] = calloc(size, sizeof(int));
		for (int j = 0; j < size; j++)
		{
			if (input[i][j] == '#')
			{
				map[i][j] = galaxy;
				galaxy++;
			}
		}
	}
}

static void	empty_space(char** input, int* empty_rows, int* empty_cols)
{

}

void	silver_day10(char** input)
{
	int result;
	int**	map;
	int	empty_rows[140];
	int	empty_cols[140];
	int x;

	for (int i = 0; i < size; i++)
	{
		if (strchr(input[i], '#') == NULL)
		{
			empty_rows[x] = i;
			x++;
		}
	}
	x = 0;
	for (int j = 0; j < size; j++)
	{
		for (int i = 0; i < size; i++)
		{
			if (input[i][j])
		}
	}
	map = create_map(input);
	input_stars(map);

	result = find_loop_length(map);
	printf("Silver: %d\n", result / 2 + result % 2);
}