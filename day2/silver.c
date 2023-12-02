#include "day2.h"

static bool	find_color(char* str, int res)
{
	if (*str == 'r' && res <= 12)
		return (true);
	if (*str == 'g' && res <= 13)
		return (true);
	if (*str == 'b' && res <= 14)
		return (true);
	return (false);
}

static int	convert_number(char** str)
{
	int res = 0;

	while (**str != '\0' && isdigit(**str) == true)
	{
		res *= 10;
		res += (**str - '0');
		(*str)++;
	}
	printf("res: %d\n", res);
	return (res);
}

static bool	game_x(char* input)
{
	int num = 0;

	while (*input != '\0' && isdigit(*input) == false)
		input++;
	if (*input == '\0')
		return (true);
	num = convert_number(&input);
	input++;
	if (find_color(input, num) == true)
		if (game_x(input) == true)
			return (true);
	return (false);
}

int main(void)
{
	FILE* 	file;
	char* 	tmp;
	char**	input;
	int 	size; int i = 0;
	bool	*result;
	int		result2 = 0;

	file = fopen("input.txt", "r");
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	rewind(file);
	tmp = calloc((size + 1), sizeof(char));
	fread(tmp, sizeof(char), size, file);

	result = calloc(100, sizeof(bool));
	if (result == NULL)
		return (1);
	input = ft_split(tmp, '\n');
	if (input == NULL)
		return (1);

	while (*input != NULL)
	{
		while (**input != ':')
			(*input)++;
		(*input) += 2;
		result[i] = game_x(*input);
		printf("Result[%d]: %d\n", i + 1, (int)result[i]);
		i++;
		input++;
	}
	
	for (int i = 0; i < 100; i++)
	{
		if (result[i] == true)
			result2 += (i + 1);
	}

	printf("Result: %d\n", result2);
	fclose(file);
}
