/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 17:01:41 by seongkim          #+#    #+#             */
/*   Updated: 2020/09/22 22:11:20 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_handle_width(int width, int flag)
{
	int		count;
	char	w;

	count = 0;
	w = ' ';
	if (flag == 1)
		w = '0';
	while (width > 0)
	{
		count += ft_putchar(w);
		width--;
	}
	return (count);
}
