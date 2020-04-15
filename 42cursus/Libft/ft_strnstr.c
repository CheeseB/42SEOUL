/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongki@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 19:26:55 by seongkim          #+#    #+#             */
/*   Updated: 2020/04/15 11:46:34 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lit_len;

	if (!*lit)
		return ((char *)big);
	i = 0;
	lit_len = ft_strlen(lit);
	while (i <= len - lit_len)
	{
		j = 0;
		while (j < lit_len && big[i + j] == lit[j])
			j++;
		if (j == lit_len)
			return ((char *)(big + i));
		i++;
	}
	return (0);
}
