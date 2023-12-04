#include "day4.h"

static int	ft_getamount(const char *s, char c)
{
	int	i;
	int	amount;

	i = 0;
	amount = 0;
	while (*s == c && c != '\0')
		s++;
	if (s[i])
		amount++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			amount++;
		i++;
	}
	return (amount);
}

static void	ft_free(char **s2)
{
	int	x;

	x = 0;
	while (s2[x])
	{
		free(s2[x]);
		x++;
	}
	free(s2);
}

static char	**ft_crearray(char **s2, const char *s, char c, int len)
{
	int	x;

	x = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			return (s2);
		if (strchr(s, c) == NULL)
		{
			s2[x] = strdup(s);
			if (!s2[x])
				return (ft_free(s2), NULL);
			return (s2);
		}
		len = (strchr(s, c)) - s;
		s2[x] = malloc((len + 1) * sizeof(char));
		if (!s2[x])
			return (ft_free(s2), NULL);
		strlcpy(s2[x], s, len + 1);
		s += len;
		x++;
	}
	return (s2);
}

char	**ft_split(const char *s, char c)
{
	char	**out;
	int		amount;
	int		len;

	if (!s)
		return (NULL);
	len = 0;
	amount = ft_getamount(s, c);
	out = malloc((amount + 1) * sizeof(char *));
	if (!out)
		return (NULL);
	if (amount == 0)
		return (*out = NULL, out);
	out = ft_crearray(out, s, c, len);
	if (!out)
		return (NULL);
	out[amount] = NULL;
	return (out);
}
