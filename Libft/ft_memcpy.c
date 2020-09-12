/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongki@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 19:24:30 by seongkim          #+#    #+#             */
/*   Updated: 2020/04/24 17:39:21 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*result;

	if (!dst && !src)
		return (0);
	result = (unsigned char *)dst;
	while (len--)
	{
		*result = *(unsigned char *)src;
		result++;
		src++;
	}
	return (dst);
}
