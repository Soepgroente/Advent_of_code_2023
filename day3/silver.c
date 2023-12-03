#include "day3.h"

static bool is_symbol(char c)
{
	if (isdigit(c) == false && c != '.' && c != '\0')
		return (true);
	return (false);
}

static bool	part_of_schematics(char** input, int i, int j)
{
	if (j > 0)
	{
		if (is_symbol(input[i][j - 1]) == true)
			return (true);
		if ((i > 0 && is_symbol(input[i - 1][j - 1]) == true) || \
			(input[i + 1] != NULL && is_symbol(input[i + 1][j - 1]) == true))
			return (true);
	}
	while (isdigit(input[i][j]) == true)
	{
		if ((i > 0 && is_symbol(input[i - 1][j]) == true) || (input[i + 1] != NULL && is_symbol(input[i + 1][j]) == true))
			return (true);
		j++;
	}
	if (is_symbol(input[i][j]) == true || (i > 0 && is_symbol(input[i - 1][j]) == true) || \
		(input[i + 1] != NULL && is_symbol(input[i + 1][j]) == true))
		return (true);
	return (false);
}

static uint64_t	complete_number(char* str, int i)
{
	uint64_t num = 0;
	while (str[i] != '\0' && isdigit(str[i]) == true)
	{
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return (num);
}

static uint64_t	add_up_schematics(char** input)
{
	int i = 0; int j; uint64_t total = 0;

	while (input[i] != NULL)
	{
		j = 0;
		while (input[i][j] != '\0')
		{
			if (isdigit(input[i][j]) == true && part_of_schematics(input, i, j) == true)
			{
				total += complete_number(input[i], j);
				while (isdigit(input[i][j + 1]) == true)
					j++;
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
	int 	size;

	file = fopen("input.txt", "r");
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	rewind(file);
	tmp = calloc((size + 1), sizeof(char));
	fread(tmp, sizeof(char), size, file);
	input = ft_split(tmp, '\n');
	if (input == NULL)
		return (1);

	printf("Result: %llu\n", add_up_schematics(input));
	fclose(file);
}
