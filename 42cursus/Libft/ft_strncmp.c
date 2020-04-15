/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongki@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 19:26:48 by seongkim          #+#    #+#             */
/*   Updated: 2020/04/11 19:26:50 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	int	sub;

	sub = 0;
	while ((*s1 || *s2) && len--)
	{
		sub = *(unsigned char *)s1++ - *(unsigned char *)s2++;
		if (sub != 0)
			return (sub);
	}
	return (0);
}
