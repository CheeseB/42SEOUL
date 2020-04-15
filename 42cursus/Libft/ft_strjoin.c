/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongki@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 19:26:09 by seongkim          #+#    #+#             */
/*   Updated: 2020/04/11 19:35:03 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	idx;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(ptr = (char *)malloc(sizeof(char) * len)))
		return (0);
	idx = 0;
	while (*s1)
		ptr[idx++] = *s1++;
	while (*s2)
		ptr[idx++] = *s2++;
	ptr[idx] = 0;
	return (ptr);
}
