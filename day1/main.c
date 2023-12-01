#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char	**ft_split(const char *s, char c);

int	compare_input(char* input)
{
	char c = *input;

	if (c >= '1' && c <= '9')
		return ((c - '0'));
	if (strncmp(input, "one", 3) == 0)
		return (1);
	if (strncmp(input, "two", 3) == 0)
		return (2);
	if (strncmp(input, "three", 5) == 0)
		return (3);
	if (strncmp(input, "four", 4) == 0)
		return (4);
	if (strncmp(input, "five", 4) == 0)
		return (5);
	if (strncmp(input, "six", 3) == 0)
		return (6);
	if (strncmp(input, "seven", 5) == 0)
		return (7);
	if (strncmp(input, "eight", 5) == 0)
		return (8);
	if (strncmp(input, "nine", 4) == 0)
		return (9);
	return (0);
}

int	convert_str_to_int(char* input)
{
	int	i = 0; int res = 0;

	while (input[i] != '\0' && compare_input(&input[i]) == 0)
		i++;
	res += compare_input(&input[i]) * 10;
	i = strlen(input) - 1;
	while (i > 0 && compare_input(&input[i]) == 0)
		i--;
	res += compare_input(&input[i]);
	return (res);
}

int main(void)
{
	FILE* 	file;
	char* 	tmp;
	char**	input;
	int 	size;
	int 	result = 0;

	file = fopen("input.txt", "r");
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	rewind(file);
	tmp = calloc((size + 1), sizeof(char));
	fread(tmp, sizeof(char), size, file);
	input = ft_split(tmp, '\n');
	for (int i = 0; input[i] != NULL; i++)
		result += convert_str_to_int(input[i]);
	printf("Result: %d\n", result);
	fclose(file);
}
