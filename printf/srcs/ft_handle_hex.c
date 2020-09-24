/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:04:29 by seongkim          #+#    #+#             */
/*   Updated: 2020/09/22 22:12:02 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_input(char *str, t_flag flag)
{
	int		count;

	count = 0;
	if (flag.dot >= 0)
		count += ft_handle_width(flag.dot - ft_strlen(str), 1);
	count += ft_putnstr(str, ft_strlen(str));
	return (count);
}

static int	ft_put_hex(char *str, t_flag flag)
{
	int		count;

	count = 0;
	if (flag.minus == 1)
		count += ft_input(str, flag);
	if (flag.dot >= 0 && flag.dot < ft_strlen(str))
		flag.dot = ft_strlen(str);
	if (flag.dot >= 0)
	{
		flag.width -= flag.dot;
		count += ft_handle_width(flag.width, 0);
	}
	else
		count += ft_handle_width(flag.width - ft_strlen(str), flag.zero);
	if (flag.minus == 0)
		count += ft_input(str, flag);
	return (count);
}

int			ft_handle_hex(unsigned int n, int is_large, t_flag flag)
{
	int		count;
	char	*str;

	count = 0;
	n = (unsigned int)(4294967295 + 1 + n);
	if (flag.dot == 0 && n == 0)
	{
		count += ft_handle_width(flag.width, 0);
		return (count);
	}
	str = ft_hex_itoa(n);
	if (is_large == 1)
		str = ft_str_toupper(str);
	count += ft_put_hex(str, flag);
	free(str);
	return (count);
}