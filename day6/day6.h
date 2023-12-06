#ifndef DAY6_H
# define DAY6_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <limits.h>
#include <math.h>

char		**ft_split(const char *s, char c);
void		silver_day6(char** input);
void		gold_day6(char** input);
uint64_t	advtoi(char** str);
uint64_t	advtoi2(char** str);

#endif