#include "day12.h"

uint64_t	advtoi(char** str)
{
	uint64_t num = 0;

	while (**str != '\0' && isdigit(**str) == true)
	{
		num *= 10;
		num += **str - '0';
		(*str)++;
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

void	printeger_2d(int** array, int xs, int ys)
{
	for (int x = 0; x < xs; x++)
	{
		for (int y = 0; y < ys; y++)
		{
			if (array[x][y] == 0)
				printf(".");
			else if (array[x][y] == -1)
				printf("!");
			else
				printf("#");
		}
		printf("\n");
	}
	puts("\n");
	print_yx(array);
}