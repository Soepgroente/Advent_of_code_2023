#include "day2.h"

static int	find_color(char* str)
{
	if (*str == 'r')
		return (RED);
	if (*str == 'g')
		return (GREEN);
	if (*str == 'b')
		return (BLUE);
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
	return (res);
}

static void	game_x(char* input, int* red, int* green, int* blue)
{
	int tmp = 0;

	while (*input != '\0' && isdigit(*input) == false)
		input++;
	if (*input == '\0')
		return ;
	tmp = convert_number(&input);
	input++;
	if (find_color(input) == RED && tmp > *red)
		*red = tmp;
	else if (find_color(input) == GREEN && tmp > *green)
		*green = tmp;
	else if (find_color(input) == BLUE && tmp > *blue)
		*blue = tmp;
	game_x(input, red, green, blue);
	return ;
}

int main(void)
{
	FILE* 	file;
	char* 	tmp;
	char**	input;
	int 	size;
	uint64_t	result = 0;
	int red, green, blue;

	file = fopen("input.txt", "r");
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	rewind(file);
	tmp = calloc((size + 1), sizeof(char));
	fread(tmp, sizeof(char), size, file);
	fclose(file);

	input = ft_split(tmp, '\n');
	if (input == NULL)
		return (1);

	while (*input != NULL)
	{
		red = 0; green = 0; blue = 0;
		while (**input != ':')
			(*input)++;
		(*input) += 2;
		game_x(*input, &red, &green, &blue);
		result += red * green * blue;
		input++;
	}

	printf("Result: %llu\n", result);
}
