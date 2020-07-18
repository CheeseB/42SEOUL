/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongki@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 11:45:40 by seongkim          #+#    #+#             */
/*   Updated: 2020/07/15 11:45:47 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strncpy(char *dst, char *src, size_t n)
{
	size_t i;

	if (dst == 0 && src == 0)
		return (dst);
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

char	*ft_strchr(char *s, int c)
{
	if (c == 0)
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	idx;
	size_t	len;

	if (!s1 || !s2)
		return (0);
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

char	*ft_strndup(char *str, size_t size)
{
	char	*ptr;

	if (!(ptr = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	ft_strncpy(ptr, str, size);
	ptr[size] = 0;
	return (ptr);
}
