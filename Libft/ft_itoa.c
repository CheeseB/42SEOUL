/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongki@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 19:23:51 by seongkim          #+#    #+#             */
/*   Updated: 2020/04/26 22:22:49 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_length(int n)
{
	if (n / 10)
		return (1 + get_length(n / 10));
	return (1);
}

char		*ft_itoa(int n)
{
	char	*ptr;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!n)
		return (ft_strdup("0"));
	len = get_length(n);
	if (n < 0)
		len++;
	if (!(ptr = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (n < 0)
	{
		ptr[0] = '-';
		n *= -1;
	}
	ptr[len] = 0;
	while (n)
	{
		ptr[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (ptr);
}
