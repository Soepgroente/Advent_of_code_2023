#include "day11.h"

int x_size;
int y_size;
int galaxies;

static int**	set_coordinates(int** map)
{
	int**	locs;
	int 	i = 0;

	locs = calloc(galaxies, sizeof(int*));
	for (int z = 0; z < galaxies; z++)
		locs[z] = calloc(2, sizeof(int));
	for (int x = 0; x < x_size; x++)
	{
		for (int y = 0; y < y_size; y++)
		{
			if (map[x][y] != 0)
			{
				locs[i][0] = x;
				locs[i][1] = y;
				i++;
			}
		}
	}
	return (locs);
}

static int**	create_map(char** input, int* empty_rows, int* empty_cols)
{
	int**	map;
	int 	galaxy = 1;
	int x = 0; int y = 0;

	map = calloc(x_size, sizeof(int*));
	if (map == NULL)
		exit(EXIT_FAILURE);
	for (int i = 0; i < x_size; i++)
	{
		y = 0;
		map[i] = calloc(y_size, sizeof(int));
		if (map[i] == NULL)
			exit(EXIT_FAILURE);
		for (int j = 0; j < y_size; j++)
		{
			if (input[i - x][j - y] == '#')
			{
				map[i][j] = galaxy;
				galaxy++;
			}
			if (empty_cols[y] == j - y)
			{
				y++;
				j++;
			}
		}
		if (empty_rows[x] == i - x)
		{
			x++;
			i++;
			map[i] = calloc(y_size, sizeof(int));
			if (map[i] == NULL)
				exit(EXIT_FAILURE);
		}			
	}
	galaxies = galaxy - 1;
	return (map);
}

void	silver_day11(char** input)
{
	int**	map;
	int 	size;
	int*	empty_rows;
	int*	empty_cols;
	int x = 0;
	int**	locs;
	uint64_t	result = 0;

	size = count_array(input);
	x_size = size;
	y_size = strlen(*input);
	empty_rows = calloc(size, sizeof(int));
	empty_cols = calloc(size, sizeof(int));
	for (int i = 0; i < size; i++)
	{
		if (strchr(input[i], '#') == NULL)
		{
			empty_rows[x] = i;
			x_size++;
			x++;
		}
	}
	x = 0;
	for (int j = 0; j < y_size; j++)
	{
		empty_cols[x] = j;
		for (int i = 0; i < size; i++)
		{
			if (input[i][j] == '#')
				empty_cols[x] = 0;
		}
		if (empty_cols[x] != 0)
			x++;
	}
	y_size += x;
	map = create_map(input, empty_rows, empty_cols);
	locs = set_coordinates(map);
	for (x = 0; x < galaxies - 1; x++)
		for (int y = x + 1; y < galaxies; y++)
			result += abs(locs[x][0] - locs[y][0]) + abs(locs[x][1] - locs[y][1]);
	printf("Silver: %llu\n", result);
}