/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:04:29 by seongkim          #+#    #+#             */
/*   Updated: 2020/09/22 17:26:19 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_char(char c, t_flag flag)
{
	int count;

	count = 0;
	flag.width--;
	if (flag.minus == 1)
	{
		count += ft_putchar(c);
		count += ft_handle_width(flag.width, 0);
	}
	else
	{
		count += ft_handle_width(flag.width, 0);
		count += ft_putchar(c);
	}
	return (count);
}
