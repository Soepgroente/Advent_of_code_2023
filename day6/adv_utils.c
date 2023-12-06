#include "day6.h"

uint64_t	advtoi(char** str)
{
	uint64_t num = 0;

	while (**str != '\0' && isdigit(**str) == true)
	{
		num *= 10;
		num += **str - '0';
		(*str)++;
	}
	while (**str != '\0' && isdigit(**str) == false)
		(*str)++;
	return (num);
}

int	count_array(char** array)
{
	int i = 0;

	while (array[i] != NULL)
		i++;
	return (i);
}

uint64_t	advtoi2(char** str)
{
	uint64_t num = 0;

	while (**str != '\0' && isdigit(**str) == false)
		(*str)++;
	while (**str != '\0' && isdigit(**str) == true)
	{
		num *= 10;
		num += **str - '0';
		(*str)++;
		while (**str == ' ')
			(*str)++;
	}
	return (num);
}