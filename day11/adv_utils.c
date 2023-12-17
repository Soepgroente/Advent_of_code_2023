#include "day11.h"

uint64_t	advtoi(char* str)
{
	uint64_t num = 0;

	while (*str != '\0' && isdigit(*str) == false)
		str++;
	while (*str != '\0' && isdigit(*str) == true)
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	return (num);
}

int	count_array(char** array)
{
	int i = 0;

	while (array[i] != NULL)
		i++;
	return (i);
}

void	print_2d(char** array)
{
	int i = 0;

	while (array[i] != NULL)
	{
		printf("%s\n", array[i]);
		i++;
	}
}

static void print_yx(int** array)
{
	return ;
	for (int x = 0; x < y_size; x++)
	{
		for (int y = 0; y < x_size; y++)
		{
			if (array[y][x] == 0)
				printf(".");
			else
				printf("#");
		}
		printf("\n");
	}
}

void	printeger_2d(int** array)
{
	for (int x = 0; x < x_size; x++)
	{
		for (int y = 0; y < y_size; y++)
		{
			if (array[x][y] == 0)
				printf(".");
			else
				printf("#");
		}
		printf("\n");
	}
	puts("\n");
	print_yx(array);
}