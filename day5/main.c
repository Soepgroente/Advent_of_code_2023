#include "day5.h"

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

	silver_day5(input);
	fclose(file);
}
