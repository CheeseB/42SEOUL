#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*result;
	
	result = (unsigned char *)dst;
	while (len--)
	{
		*result = *(unsigned char *)src;
		result++;
		src++;
	}
	return (dst);
}
