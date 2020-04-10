#include "libft.h"

void	ft_bzero(void *b, size_t len)
{
	while (len--)
	{
		*(unsigned char *)b = 0;
		b++;
	}
}
