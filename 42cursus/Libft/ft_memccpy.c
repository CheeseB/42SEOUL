/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongki@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 19:24:02 by seongkim          #+#    #+#             */
/*   Updated: 2020/04/11 19:29:13 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	unsigned char	src_char;

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
