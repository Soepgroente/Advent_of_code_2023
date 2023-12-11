#include "day10.h"

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