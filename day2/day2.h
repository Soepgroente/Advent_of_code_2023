#ifndef DAY2_H
# define DAY2_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <limits.h>

enum colors
{
	RED,
	GREEN,
	BLUE
};

char	**ft_split(const char *s, char c);

#endif