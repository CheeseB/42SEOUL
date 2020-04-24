/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongki@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 19:24:54 by seongkim          #+#    #+#             */
/*   Updated: 2020/04/24 17:56:38 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*result;

	if (!dst && !src)
		return (0);
	result = dst;
	if (dst > src)
	{
		dst += len - 1;
		src += len - 1;
		while (len--)
		{
			*(unsigned char *)dst = *(unsigned char *)src;
			dst--;
			src--;
		}
	}
	else
		while (len--)
		{
			*(unsigned char *)dst = *(unsigned char *)src;
			dst++;
			src++;
		}
	return (result);
}
