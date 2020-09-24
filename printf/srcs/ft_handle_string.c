/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:04:29 by seongkim          #+#    #+#             */
/*   Updated: 2020/09/22 17:18:19 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_string(char *s, t_flag flag)
{
	int count;
	int	len;
	int	i;

	count = 0;
	i = 0;
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (flag.dot > -1)
		len = len > flag.dot ? flag.dot : len;
	flag.width -= len;
	if (flag.minus == 1)
	{
		while (i < len)
			count += ft_putchar(s[i++]);
		count += ft_handle_width(flag.width, 0);
	}
	else
	{
		count += ft_handle_width(flag.width, flag.zero);
		while (i < len)
			count += ft_putchar(s[i++]);
	}
	return (count);
}
