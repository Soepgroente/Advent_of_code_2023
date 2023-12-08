#include "day8.h"

int	ft_sqrt(uint64_t num)
{
	uint64_t i = 0;
	
	while (i * i < num)
		i++;
	return ((int) i);
}

int	next_prime(int prime)
{
	int i = 2;

	while (i < prime)
	{
		if (prime % i == 0)
		{
			prime++;
			i = 1;
		}
		i++;
	}
	return (prime);
}

int	greatest_common_divisor(int a, int b)
{
	while (b != 0)
	{
		a = a % b;
		b ^= a;
		a ^= b;
		b ^= a;
	}
	return (a);
}

uint64_t	find_greatest_common_factor(uint64_t nums[])
{
	int div;

	for (int i = 0; i < 6; i++)
	{
		for (int j = i + 1; j < 6; j++)
		{
			div = greatest_common_divisor(nums[i], nums[j]);
		}
	}
	return (div);
}
