#include "day8.h"

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

int	advatoi2(char** str)
{
	int	res = 0;

	while (isalpha(**str) == false)
		(*str)++;
	while (**str >= 'A' && **str <= 'Z')
	{
		res *= 100;
		res += **str;
		(*str)++;
	}
	return (res);
}

int	count_array(char** array)
{
	int i = 0;

	while (array[i] != NULL)
		i++;
	return (i);
}
