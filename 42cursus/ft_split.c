#include "libft.h"

static int	split_copy(char **ptr, char const *s, char c)
{
	size_t	row;
	size_t	col;
	char	*start;

	row = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = (char *)s;
			while (*s && *s != c)
				s++;
			if (!(ptr[row] = (char *)malloc(sizeof(char) * (s - start + 1))))
				return (0);
			col = 0;
			while (start < s)
				ptr[row][col++] = *start++;
			ptr[row][col] = 0;
			row++;
		}
		else
			s++;
	}
	return (1);
}

char		**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	if(!(ptr = (char **)malloc(sizeof(char *) * (count + 1))))
		return (0);
	ptr[count] = 0;
	if(!split_copy(ptr, s, c))
		return (0);
	return (ptr);
}
