/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongki@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 19:24:19 by seongkim          #+#    #+#             */
/*   Updated: 2020/04/11 19:24:21 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	int	sub;

	sub = 0;
	while (len--)
	{
		sub = *(unsigned char *)b1 - *(unsigned char *)b2;
		if (sub != 0)
			return (sub);
		b1++;
		b2++;
	}
	return (0);
}
