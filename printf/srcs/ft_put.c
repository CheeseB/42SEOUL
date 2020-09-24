/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 22:31:43 by seongkim          #+#    #+#             */
/*   Updated: 2020/09/22 22:32:57 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putnstr(char *str, int size)
{
	int	i;

	i = 0;
	while (str[i] && i < size)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
