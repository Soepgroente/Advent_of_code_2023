#include "day8.h"

t_map*	new_node(int location, int left, int right, t_map* first)
{
	t_map*	new;

	new = calloc(1, sizeof(t_map));
	if (new == NULL)
		exit(EXIT_FAILURE);
	new->loc = location;
	new->left = left;
	new->right = right;
	new->first = first;
	new->nx = NULL;
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
	node->first = *map;
	if (*map == NULL)
		*map = node;
	else
	{
		*map = map_last(*map);
		(*map)->nx = node;
		*map = node->first;
	}
}

t_map*	find_in_map(t_map* map, int location)
{
	while (map != NULL)
	{
		if (map->loc == location)
			return (map);
		map = map->nx;
	}
	puts("Couldn't find location");
	exit(EXIT_FAILURE);
}


void	print_node(t_map* map)
{
	printf("%c%c%c = (", map->loc / 10000, (map->loc / 100) % 100, map->loc % 100);
	printf("%c%c%c, ", map->left / 10000, (map->left / 100) % 100, map->left % 100);
	printf("%c%c%c)\n", map->right / 10000, (map->right / 100) % 100, map->right % 100);
	printf("\n");
}

void	print_map(t_map* map)
{
	while (map != NULL)
	{
		// printf("first: %p location: %d left: %d right: %d\n", map->first, map->loc, map->left, map->right);
		printf("%c%c%c = (", map->loc / 10000, (map->loc / 100) % 100, map->loc % 100);
		printf("%c%c%c, ", map->left / 10000, (map->left / 100) % 100, map->left % 100);
		printf("%c%c%c)\n", map->right / 10000, (map->right / 100) % 100, map->right % 100);
		map = map->nx;
	}
	printf("\n");
}