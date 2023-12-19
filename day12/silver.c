#include "day12.h"

int*	damaged;
int 	len;

static t_map*	parse_configs(char* input)
{
	t_map*	configs;
	char 	c;
	int		count;
	int i = 0;

	while (input[i] != ' ')
		i++;
	len = i;
	i = 0;
	while (isdigit(*input) == false)
	{
		c = *input;
		count = 0;
		while (*input == c)
		{
			input++;
			count++;
		}
		map_add_back(&configs, new_node(c, count));
	}
	while (*input != '\0')
	{
		damaged[i] = advtoi(&input);
		i++;
		if (*input != '\0')
			input++;
	}
	return (configs);
}

static uint64_t	calc_configs(char* input)
{
	t_map*		configs;
	t_map*		head;
	uint64_t	options = 0;
	int tmp = 0; int i = 0;

	configs = parse_configs(input);
	head = configs;
	
	if (configs->status == WORKS)
		configs = configs->nx;
	while (configs != NULL)
	{
		if (configs->status == WORKS)

	}
	clear_list(&head);
	return (options);
}

void	silver_day12(char** input)
{
	uint64_t result = 0;

	damaged = calloc(10, sizeof(int));
	for (int i = 0; input[i] != NULL; i++)
	{
		result += calc_configs(input[i]);
		for (int j = 0; j < 10; j++)
			damaged[j] = 0;
	}
	printf("Silver: %llu\n", result);
}