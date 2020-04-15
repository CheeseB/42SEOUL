/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongki@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 19:24:11 by seongkim          #+#    #+#             */
/*   Updated: 2020/04/11 19:24:13 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	while (len--)
	{
		if (*(unsigned char *)b == (unsigned char)c)
			return ((void *)b);
		b++;
	}
	return (0);
}
