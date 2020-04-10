#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	while (len--)
	{
		if (*(unsigned char *)b == (unsigned char)c)
			return ((void *)b);
		b++;
	}
	return (0);
}
