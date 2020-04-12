/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongki@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 19:23:51 by seongkim          #+#    #+#             */
/*   Updated: 2020/04/11 19:23:53 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_length(int n)
{
	if (n / 10)
		return (1 + get_length(n / 10));
	return (1);
}

static int	get_digit(int len)
{
	if (len - 1)
		return (10 * get_digit(len - 1));
	return (1);
}

static void	fill_ptr(char *ptr, int digit, int n, int i)
{
	while (digit)
	{
		ptr[i++] = (n / digit) + '0';
		n %= digit;
		digit /= 10;
	}
	ptr[i] = 0;
}

char		*ft_itoa(int n)
{
	char	*ptr;
	int		len;
	int		digit;
	int		i;

	if (n == -2147483648)
		return ("-2147483648");
	len = get_length(n);
	if (n < 0)
		len++;
	if (!(ptr = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	if (n < 0)
	{
		len--;
		n *= -1;
		ptr[i++] = '-';
	}
	digit = get_digit(len);
	fill_ptr(ptr, digit, n, i);
	return (ptr);
}
