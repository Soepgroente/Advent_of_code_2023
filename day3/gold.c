#include "day3.h"

static uint64_t	calc_number(char* str, int i)
{
	uint64_t num = 0;

	while (i > 0 && isdigit(str[i - 1]) == true)
		i--;
	while (str[i] != '\0' && isdigit(str[i]) == true)
	{
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return (num);
}

static uint64_t	find_number(char* str, int i, int* count)
{
	uint64_t num = 1;

	if (isdigit(str[i]) == true)
	{
		num *= calc_number(str, i);
		(*count)++;
	}
	if (isdigit(str[i + 1]) == true && isdigit(str[i]) == false)
	{
		num *= calc_number(str, i + 1);
		(*count)++;
	}
	if (i > 0 && isdigit(str[i - 1]) == true && isdigit(str[i]) == false)
	{
		num *= calc_number(str, i - 1);
		(*count)++;
	}
	return (num);
}

static uint64_t	gear_product(char** input, uint64_t i, uint64_t j)
{
	uint64_t gear = 1;
	int count = 0;

	gear *= find_number(input[i], j, &count);
	if (i > 0)
		gear *= find_number(input[i - 1], j, &count);
	if (input[i + 1] != NULL)
		gear *= find_number(input[i + 1], j, &count);
	if (count == 2)
		return (gear);
	return (0);
}

static uint64_t	add_up_gears(char** input)
{
	int i = 0; 
	int j; 
	uint64_t total = 0;

	while (input[i] != NULL)
	{
		j = 0;
		while (input[i][j] != '\0')
		{
			if (input[i][j] == '*')
			{
				// printf("gear product: %lld\n", gear_product(input, i, j));
				total += gear_product(input, i, j);
			}
			j++;
		}
		i++;
	}
	return (total);
}

int main(void)
{
	FILE* 	file;
	char* 	tmp;
	char**	input;
	uint64_t 	size;

	file = fopen("input.txt", "r");
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	rewind(file);
	tmp = calloc((size + 1), sizeof(char));
	fread(tmp, sizeof(char), size, file);
	input = ft_split(tmp, '\n');
	if (input == NULL)
		return (1);

	printf("Result: %llu\n", add_up_gears(input));
	fclose(file);
}
