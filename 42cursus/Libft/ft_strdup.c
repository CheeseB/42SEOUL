/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongki@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 19:26:01 by seongkim          #+#    #+#             */
/*   Updated: 2020/04/11 19:26:03 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	size_t	idx;
	char	*ptr;

	len = ft_strlen(str);
	if (!(ptr = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	idx = 0;
	while (idx < len)
	{
		ptr[idx] = str[idx];
		idx++;
	}
	ptr[idx] = 0;
	return (ptr);
}
