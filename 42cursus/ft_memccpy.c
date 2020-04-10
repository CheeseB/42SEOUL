#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	unsigned char src_char;
	
	while (len--)
	{
		src_char = *(unsigned char *)src;
		*(unsigned char *)dst = src_char;
		dst++;
		src++;
		if (src_char == c)
			return (dst);
	}
	return (0);
}
