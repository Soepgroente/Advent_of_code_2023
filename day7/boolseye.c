#include "day7.h"

bool	is_quads(int* hand, int num)
{
	int i; int count = 0;

	for (i = 0; i < 5; i++)
	{
		if (hand[i] == num)
			count++;
	}
	if (count == 4)
		return (true);
	return (false);
}

bool	is_trips(int* hand, int num)
{
	int i; int count = 0;

	for (i = 0; i < 5; i++)
	{
		if (hand[i] == num)
			count++;
	}
	if (count == 3)
		return (true);
	return (false);
}

bool	is_pair(int* hand, int num)
{
	int i; int count = 0;

	for (i = 0; i < 5; i++)
	{
		if (hand[i] == num)
			count++;
	}
	if (count == 2)
		return (true);
	return (false);
}

bool	is_another_pair(int* hand, int pos)
{
	if (hand[pos] == hand[pos + 1])
		return (true);
	return (false);
}

bool	is_sorted(int* hand)
{
	for (int i = 0; i < 4; i++)
		if (hand[i] < hand[i + 1])
			return (false);
	return (true);
}