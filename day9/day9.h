#ifndef DAY9_H
# define DAY9_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <limits.h>
#include <math.h>

char	**ft_split(const char *s, char c);
void	silver_day9(char** input);
void	gold_day9(char** input);
int		advtoi(char* str);
int		count_array(char** array);
void	free_charray(char** split);

void	print_sequence(int* nums, int size);

#endif