/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:04:29 by seongkim          #+#    #+#             */
/*   Updated: 2020/09/22 22:13:01 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_input(char *str, t_flag flag)
{
	int		count;

	count = 0;
	count += ft_putnstr("0x", 2);
	if (flag.dot >= 0)
	{
		count += ft_handle_width(flag.dot - ft_strlen(str), 1);
		count += ft_putnstr(str, flag.dot);
	}
	else
		count += ft_putnstr(str, ft_strlen(str));
	return (count);
}

static int	ft_put_pointer(char *str, t_flag flag)
{
	int		count;

	count = 0;
	if (flag.dot < ft_strlen(str))
		flag.dot = ft_strlen(str);
	if (flag.minus == 1)
		count += ft_input(str, flag);
	count += ft_handle_width(flag.width - ft_strlen(str) - 2, 0);
	if (flag.minus == 0)
		count += ft_input(str, flag);
	return (count);
}

int			ft_handle_pointer(unsigned long long p, t_flag flag)
{
	int		count;
	char	*str;

	count = 0;
	if (flag.dot == 0 && p == 0)
	{
		if (flag.width >= 0 && flag.minus == 0)
		{
			count += ft_handle_width(flag.width - 2, 0);
			count += ft_putnstr("0x", 2);
		}
		else
		{
			count += ft_putnstr("0x", 2);
			count += ft_handle_width(flag.width - 2, 0);
		}
		return (count);
	}
	str = ft_hex_itoa(p);
	count += ft_put_pointer(str, flag);
	free(str);
	return (count);
}
