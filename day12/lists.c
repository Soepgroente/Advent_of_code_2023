#include "day12.h"

static t_token	get_symbol(char symbol)
{
	if (symbol == '.')
		return (WORKS);
	if (symbol == '#')
		return (BROKEN);
	if (symbol == '?')
		return (QUESTIONMARK);
	puts("Couldn't find symbol");
	exit(EXIT_FAILURE);
}

t_map*	new_node(char symbol, int amount)
{
	t_map*	new;

	new = calloc(1, sizeof(t_map));
	if (new == NULL)
		exit(EXIT_FAILURE);
	new->nx = NULL;
	new->pv = NULL;
	new->amount = amount;
	new->status = get_symbol(symbol);
	return (new);
}

t_map*	map_last(t_map* map)
{
	while (map->nx != NULL)
		map = map->nx;
	return (map);
}

void	clear_list(t_map** list)
{
	t_map* tmp;

	tmp = *list;
	while (*list != NULL)
	{
		tmp = (*list)->nx;
		free(*list);
		*list = tmp;
	}
}

void	map_add_back(t_map** map, t_map* node)
{
	t_map*	tmp;

	tmp = *map;
	if (*map == NULL)
		*map = node;
	else
	{
		*map = map_last(*map);
		(*map)->nx = node;
		node->pv = *map;
		*map = tmp;
	}
}

void	print_map(t_map* map)
{
	t_map*	tmp;

	tmp = map;
	while (map != NULL)
	{
		printf("%d\n", map->amount);
		// printf("prev: %p, next: %p, up: %p, down: %p\n", map->pv, map->nx, map->up, map->down);
		map = map->nx;
	}
	printf("\n");
}