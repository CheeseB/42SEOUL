/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 22:27:25 by seongkim          #+#    #+#             */
/*   Updated: 2020/09/22 22:30:32 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		hex_num_size(long long temp)
{
	int			size;

	size = 0;
	if (temp == 0)
		return (1);
	while (temp > 0)
	{
		size++;
		temp /= 16;
	}
	return (size);
}

char			*ft_hex_itoa(unsigned long long n)
{
	int			size;
	long long	temp;
	char		*ret;

	size = 0;
	temp = n;
	size += hex_num_size(temp);
	if (!(ret = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ret[size--] = '\0';
	if ((temp = n) < 0)
		temp *= -1;
	while (size + 1 > 0)
	{
		ret[size] = HEX_BASE[temp % 16];
		temp /= 16;
		size--;
	}
	return (ret);
}

static int		num_size(long long temp)
{
	int			size;

	size = 0;
	if (temp == 0)
		return (1);
	while (temp > 0)
	{
		size++;
		temp /= 10;
	}
	return (size);
}

char			*ft_u_itoa(unsigned int n)
{
	int			size;
	long long	temp;
	char		*ret;

	size = 0;
	temp = n;
	if (temp < 0)
	{
		size++;
		temp *= -1;
	}
	size += num_size(temp);
	if (!(ret = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ret[size--] = '\0';
	if ((temp = n) < 0)
		temp *= -1;
	while ((size + 1 > 0 && n >= 0) || (size > 0 && n < 0))
	{
		ret[size--] = temp % 10 + '0';
		temp /= 10;
	}
	if (n < 0)
		ret[size] = '-';
	return (ret);
}

char			*ft_itoa(int n)
{
	int			size;
	long long	temp;
	char		*ret;

	size = 0;
	temp = n;
	if (temp < 0)
	{
		size++;
		temp *= -1;
	}
	size += num_size(temp);
	if (!(ret = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ret[size--] = '\0';
	if ((temp = n) < 0)
		temp *= -1;
	while ((size + 1 > 0 && n >= 0) || (size > 0 && n < 0))
	{
		ret[size--] = temp % 10 + '0';
		temp /= 10;
	}
	if (n < 0)
		ret[size] = '-';
	return (ret);
}
