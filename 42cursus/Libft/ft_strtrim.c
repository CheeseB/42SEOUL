/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongki@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 19:31:37 by seongkim          #+#    #+#             */
/*   Updated: 2020/04/11 19:32:35 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_start(char const *s1, char const *set)
{
	size_t	start;
	size_t	i;
	int		flag;

	start = 0;
	while (s1[start])
	{
		i = 0;
		flag = 0;
		while (set[i])
		{
			if (s1[start] == set[i])
			{
				flag = 1;
				break ;
			}
			i++;
		}
		if (!flag)
			break ;
		start++;
	}
	return (start);
}

static size_t	get_end(char const *s1, char const *set, size_t start)
{
	size_t	end;
	size_t	i;
	int		flag;

	end = ft_strlen(s1) - 1;
	while (start < end)
	{
		i = 0;
		flag = 0;
		while (set[i])
		{
			if (s1[end] == set[i])
			{
				flag = 1;
				break ;
			}
			i++;
		}
		if (!flag)
			break ;
		end--;
	}
	return (end);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	trim_start;
	size_t	trim_end;
	size_t	i;

	trim_start = get_start(s1, set);
	trim_end = get_end(s1, set, trim_start);
	if (trim_start > trim_end)
	{
		if (!(ptr = (char *)malloc(sizeof(char))))
			return (0);
		*ptr = 0;
		return (ptr);
	}
	if (!(ptr = (char *)malloc(sizeof(char) * (trim_end - trim_start + 2))))
		return (0);
	i = 0;
	while (trim_start <= trim_end)
	{
		ptr[i] = s1[trim_start];
		i++;
		trim_start++;
	}
	ptr[i] = 0;
	return (ptr);
}
