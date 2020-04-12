/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongki@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 19:26:16 by seongkim          #+#    #+#             */
/*   Updated: 2020/04/11 19:26:19 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_size;
	size_t	s_size;
	size_t	result;

	d_size = 0;
	s_size = 0;
	while (dst[d_size])
		d_size++;
	while (src[s_size])
		s_size++;
	result = s_size;
	if (dstsize <= d_size)
		result += dstsize;
	else
		result += d_size;
	s_size = 0;
	while (src[s_size] && dstsize > d_size + 1)
	{
		dst[d_size] = src[s_size];
		d_size++;
		s_size++;
	}
	dst[d_size] = '\0';
	return (result);
}
