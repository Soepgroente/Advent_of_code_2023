#include "day11.h"

int size;
int galaxies;

static uint64_t	calc_distance(int** map, int x, int y, int a, int b)
{
	uint64_t	distance = 0;
	int x_inc = 1;
	int y_inc = 1;

	if (x > a)
		x_inc *= -1;
	if (y > b)
		y_inc *= -1;
	while (x != a)
	{
		if (map[x][y] == -1)
			distance += 1000000;
		else
			++distance;
		x += x_inc;
	}
	while (y != b)
	{
		if (map[x][y] == -1)
			distance += 1000000;
		else
			++distance;
		y += y_inc;
	}
	return (distance);
}

static int**	set_coordinates(int** map)
{
	int**	locs;
	int 	i = 0;

	locs = calloc(galaxies, sizeof(int*));
	for (int z = 0; z < galaxies; z++)
		locs[z] = calloc(2, sizeof(int));
	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			if (map[x][y] < -1 || map[x][y] > 0)
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

	map = calloc(size, sizeof(int*));
	if (map == NULL)
		exit(EXIT_FAILURE);
	for (int i = 0; i < size; i++)
	{
		map[i] = calloc(size, sizeof(int));
		if (map[i] == NULL)
			exit(EXIT_FAILURE);
	}
	for (int i = 0; i < size; i++)
	{
		y = 0;
		for (int j = 0; j < size; j++)
		{
			if (input[i - x][j - y] == '#')
			{
				map[i][j] = galaxy;
				galaxy++;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (empty_rows[x] == i)
		{
			x++;
			for (int z = 0; z < size; z++)
			{
				if (map[i][z] > 0)
					map[i][z] *= -1;
				else
					map[i][z] = -1;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (empty_cols[y] == i)
		{
			y++;
			for (int z = 0; z < size; z++)
			{
				if (map[z][i] > 0)
					map[z][i] *= -1;
				else
					map[z][i] = -1;
			}
		}
	}
	galaxies = galaxy - 1;
	return (map);
}

void	gold_day11(char** input)
{
	int**	map;
	int*	empty_rows;
	int*	empty_cols;
	int x = 0;
	int**	locs;
	uint64_t	result = 0;

	size = count_array(input);
	empty_rows = calloc(size, sizeof(int));
	empty_cols = calloc(size, sizeof(int));
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
		empty_cols[x] = j;
		for (int i = 0; i < size; i++)
		{
			if (input[i][j] == '#')
				empty_cols[x] = 0;
		}
		if (empty_cols[x] != 0)
			x++;
	}
	map = create_map(input, empty_rows, empty_cols);
	printeger_2d(map, size, size);
	locs = set_coordinates(map);
	for (x = 0; x < galaxies - 1; x++)
		for (int y = x + 1; y < galaxies; y++)
			result += calc_distance(map, locs[x][0], locs[x][1], locs[y][0], locs[y][1]);
	printf("Gold: %llu\n", result);
}