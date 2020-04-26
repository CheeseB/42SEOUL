/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongki@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 19:27:09 by seongkim          #+#    #+#             */
/*   Updated: 2020/04/26 22:08:04 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
