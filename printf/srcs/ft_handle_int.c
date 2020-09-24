/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:04:29 by seongkim          #+#    #+#             */
/*   Updated: 2020/09/22 22:23:09 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_input(char *str, int n, t_flag flag)
{
	int			count;

	count = 0;
	if (n < 0 && n != -2147483648)
		count += ft_putchar('-');
	if (flag.dot >= 0)
		count += ft_handle_width(flag.dot - ft_strlen(str), 1);
	count += ft_putnstr(str, ft_strlen(str));
	return (count);
}

static int		ft_put_int(char *str, int n, t_flag flag)
{
	int			count;

	count = 0;
	if (flag.minus == 1)
		count += ft_input(str, n, flag);
	if (flag.dot >= 0 && flag.dot < ft_strlen(str))
		flag.dot = ft_strlen(str);
	if (flag.dot >= 0)
	{
		flag.width -= flag.dot;
		count += ft_handle_width(flag.width, 0);
	}
	else
	{
		if (flag.zero == 1 && n < 0 && n != -2147483648)
		{
			count += ft_putchar('-');
			n = 1;
		}
		count += ft_handle_width(flag.width - ft_strlen(str), flag.zero);
	}
	if (flag.minus == 0)
		count += ft_input(str, n, flag);
	return (count);
}

int				ft_handle_int(int n, t_flag flag)
{
	int			count;
	long long	num;
	char		*str;

	count = 0;
	num = n;
	if (flag.dot == 0 && n == 0)
	{
		count += ft_handle_width(flag.width, 0);
		return (count);
	}
	if (n < 0)
	{
		num *= -1;
		flag.width--;
	}
	str = ft_itoa(num);
	if (flag.int_space == 1 && n >= 0)
		count += ft_putchar(' ');
	count += ft_put_int(str, n, flag);
	free(str);
	return (count);
}
