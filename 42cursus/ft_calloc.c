#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (!(ptr = malloc(nmemb * size)))
		return (0);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
