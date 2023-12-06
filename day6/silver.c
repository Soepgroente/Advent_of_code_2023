#include "day6.h"

static int	calc_distance(int time, int hold)
{
	int distance;

	distance = (time - hold) * hold;
	return (distance);
}

static uint64_t	calculate_records(int time, int record)
{
	int count = 0;
	int hold = 0;

	while (hold < time)
	{
		if (calc_distance(time, hold) > record)
			count++;
		hold++;
	}
	return (count);
}

void	silver_day6(char** input)
{
	int	time[4];
	int	record[4];
	int result = 1;

	while (isdigit(**input) == false)
		(*input)++;
	for (int i = 0; i < 4; i++)
		time[i] = advtoi(input);
	input++;
	while (isdigit(**input) == false)
		(*input)++;
	for (int i = 0; i < 4; i++)
		record[i] = advtoi(input);
	for (int i = 0; i < 4; i++)
		result *= calculate_records(time[i], record[i]);
	printf("Silver: %d\n", result);
}