#ifndef DAY11_H
# define DAY11_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <limits.h>
#include <math.h>

extern int x_size;
extern int y_size;

/*	Program	*/

void		silver_day11(char** input);
void		gold_day11(char** input);

/*	Utils	*/

char		**ft_split(const char *s, char c);
uint64_t	advtoi(char* str);
int			count_array(char** array);
void		print_2d(char** array);
void		printeger_2d(int** array, int xs, int ys);

#endif