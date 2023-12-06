#include "day5.h"

t_map*	new_node(void)
{
	t_map*	new;

	new = calloc(1, sizeof(t_map));
	new->nx = NULL;
	return (new);
}

t_map*	map_last(t_map* map)
{
	while (map->nx != NULL)
		map = map->nx;
	return (map);
}

void	map_add_back(t_map* map, t_map* node)
{
	map = map_last(map);
	map->nx = node;
}

void	print_map(t_map* map)
{
	while (map != NULL)
	{
		printf("dest: %llu src: %llu range: %llu\n", map->dest, map->src, map->range);
		map = map->nx;
	}
	printf("\n");
}