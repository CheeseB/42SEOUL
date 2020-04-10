#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*result;
	
	result = (unsigned char *)dst;
	if (dst > src)
	{
		result += len - 1;
		src += len - 1;
		while (len--)
		{
			*result = *(unsigned char *)src;
			result--;
			src--;
		}
	}
	else
	{
		while (len--)
		{
			*result = *(unsigned char *)src;
			result++;
			src++;
		}
	}
	return (dst);
}
