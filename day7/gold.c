#include "day7.h"

static uint64_t	calc_distance(uint64_t time, uint64_t hold)
{
	return ((time - hold) * hold);
}

static uint64_t	calculate_records(uint64_t time, uint64_t record)
{
	uint64_t count = 0;
	uint64_t hold = 0;

	hold = record / time;
	while (hold < time)
	{
		if (calc_distance(time, hold) > record)
			count++;
		hold++;
	}
	return (count);
}

void	gold_day7(char** input)
{
	uint64_t	time;
	uint64_t	record;
	uint64_t	result;

	(void)input;
	time = 38947970;
	record = 241154910741091;
	result = calculate_records(time, record);
	printf("Gold: %llu\n", result);
}