/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongki@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 19:27:09 by seongkim          #+#    #+#             */
/*   Updated: 2020/04/11 19:32:57 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	idx;

	if (!*s || !len || (ft_strlen(s) <= start))
		return (0);
	if (!(ptr = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (s[start] && len--)
		ptr[i++] = s[start++];
	ptr[i] = 0;
	return (ptr);
}
