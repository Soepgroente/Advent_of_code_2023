#include "day7.h"

int main(void)
{
	FILE* 	file;
	char* 	tmp;
	char**	input;
	char**	tmp2;
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

	tmp2 = input;
	silver_day7(input);
	// gold_day7(tmp2);
	fclose(file);
}
