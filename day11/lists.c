#include "day10.h"

static t_token	get_symbol(char symbol)
{
	if (symbol == 'L')
		return (NORTH_EAST);
	if (symbol == 'J')
		return (NORTH_WEST);
	if (symbol == 'F')
		return (SOUTH_EAST);
	if (symbol == '7')
		return (SOUTH_WEST);
	if (symbol == '|')
		return (VERTICAL);
	if (symbol == '-')
		return (HORIZONTAL);
	if (symbol == '.')
		return (GROUND);
	if (symbol == 'S')
		return (START);
	puts("Couldn't find symbol");
	exit(EXIT_FAILURE);
}

t_map*	new_node(char symbol, t_map* first)
{
	t_map*	new;

	new = calloc(1, sizeof(t_map));
	if (new == NULL)
		exit(EXIT_FAILURE);
	new->symbolchar = symbol;
	new->symbol = get_symbol(symbol);
	new->first = first;
	if (first == NULL)
		new->first = new;
	return (new);
}

t_map*	map_last(t_map* map)
{
	while (map->nx != NULL)
		map = map->nx;
	return (map);
}

void	map_add_back(t_map** map, t_map* node)
{
	if (*map == NULL)
		*map = node;
	else
	{
		*map = map_last(*map);
		(*map)->nx = node;
		*map = node->first;
	}
}

t_map*	up_node(t_map* map)
{
	for (int i = 0; i < size; i++)
	{
		map = map->pv;
		if (map == NULL)
			return (NULL);
	}
	return (map);
}

t_map*	down_node(t_map* map)
{
	for (int i = 0; i < size; i++)
	{
		map = map->nx;
		if (map == NULL)
			return (NULL);
	}
	return (map);
}

void	print_map(t_map* map)
{
	t_map*	tmp;

	tmp = map;
	while (map != NULL)
	{
		while (map != NULL)
		{
			if (map->symbolchar == '$')
				printf("$");
			else if (map->part_of_loop == false)
				printf(".");
			else
				printf("%c", map->symbolchar);
			// printf("prev: %p, next: %p, up: %p, down: %p\n", map->pv, map->nx, map->up, map->down);
			map = map->nx;
		}
		tmp = tmp->down;
		map = tmp;
		printf("\n");
	}
}