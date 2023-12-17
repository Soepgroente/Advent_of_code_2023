#include "day11.h"

int main(int argc, char** argv)
{
	FILE* 	file;
	char* 	tmp;
	char**	input;
	int 	size;

	if (argc > 2)
	{
		puts("too much arguing");
		exit(EXIT_FAILURE);
	}
	if (argc == 2)
		file = fopen(argv[1], "r");
	else
		file = fopen("input.txt", "r");
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	rewind(file);
	tmp = calloc((size + 1), sizeof(char));
	fread(tmp, sizeof(char), size, file);

	input = ft_split(tmp, '\n');
	if (input == NULL)
		return (1);

	silver_day11(input);
	// gold_day11(input);
	fclose(file);
}
