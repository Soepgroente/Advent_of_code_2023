#include "day9.h"

int*	result;

static void	run_sequence(int* nums, int size, int* res)
{
	int i = 0;

	while (i < size - 1)
	{
		nums[i] = nums[i + 1] - nums[i];
		i++;
	}
	*res += nums[i];
	size--;
	if (size >= 0)
		run_sequence(nums, size, res);
}

static int	predict_next(char* input)
{
	char**	seq;
	int*	nums;
	int		res;
	int		size;
	int 	i;

	res = 0;
	seq = ft_split(input, ' ');
	size = count_array(seq);
	nums = calloc(size, sizeof(int));
	for (i = 0; seq[i] != NULL; i++)
		nums[i] = advtoi(seq[i]);
	run_sequence(nums, size, &res);
	free(nums);
	free_charray(seq);
	return (res);
}

void	silver_day9(char** input)
{
	int64_t total = 0;

	result = calloc(count_array(input), sizeof(int));
	for (int i = 0; input[i] != NULL; i++)
		result[i] = predict_next(input[i]);
	for (int i = 0; i < count_array(input); i++)
		total += result[i];
	printf("Silver: %lld\n", total);
}