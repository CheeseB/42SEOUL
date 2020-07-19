/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongki@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 11:45:40 by seongkim          #+#    #+#             */
/*   Updated: 2020/07/19 22:35:04 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strchr(const char *s, int c)
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	idx;

	if (!s || !len || (ft_strlen(s) <= start))
		return (ft_strdup(""));
	if (!(ptr = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	idx = 0;
	while (s[start] && len--)
		ptr[idx++] = s[start++];
	ptr[idx] = 0;
	return (ptr);
}

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

size_t	ft_strlcpy(char *dst, char const *src, size_t size)
{
	size_t		i;
	size_t		src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
