#include "day9.h"

int	advtoi(char* str)
{
	int num = 0;
	int sign = 1;

	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (*str != '\0' && isdigit(*str) == true)
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	return (num * sign);
}

int	count_array(char** array)
{
	int i = 0;

	while (array[i] != NULL)
		i++;
	return (i);
}

void	free_charray(char** split)
{
	int i = 0;

	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	print_sequence(int* nums, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", nums[i]);
	printf("\n");
}