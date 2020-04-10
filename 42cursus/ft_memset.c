#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	unsigned char	*result;

	result = (unsigned char *)dest;
	while (len--)
	{
		*result = (unsigned char)c;
		result++;
	}
	return (dest);
}
