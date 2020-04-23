/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongki@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 19:26:55 by seongkim          #+#    #+#             */
/*   Updated: 2020/04/22 16:21:52 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lit_len;

	if (!*little)
		return ((char *)big);
	i = 0;
	lit_len = ft_strlen(little);
	if (lit_len > len || lit_len > ft_strlen(big))
		return (0);
	while (i <= len - lit_len)
	{
		j = 0;
		while (j < lit_len && big[i + j] == little[j])
			j++;
		if (j == lit_len)
			return ((char *)(big + i));
		i++;
	}
	return (0);
}
