#include "day8.h"

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

	/*	Comment out silver if you want to calculate gold, it messes up the pointer	*/
	// silver_day8(input);
	gold_day8(input);
	fclose(file);
}
