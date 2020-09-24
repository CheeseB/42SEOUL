/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:04:29 by seongkim          #+#    #+#             */
/*   Updated: 2020/09/22 22:07:17 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_handle_percent(t_flag flag)
{
	int		count;
	char	z;

	z = ' ';
	count = 0;
	if (flag.minus == 1)
		count += ft_putchar('%');
	count += ft_handle_width(flag.width - 1, flag.zero);
	if (flag.minus == 0)
		count += ft_putchar('%');
	return (count);
}
