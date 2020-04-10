/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 09:11:32 by seongkim          #+#    #+#             */
/*   Updated: 2020/01/29 14:23:54 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		idx;
	int		div;
	int		mod;
	char	*hex;

	idx = 0;
	hex = "0123456789abcdef";
	while (str[idx] != '\0')
	{
		if (str[idx] < 32 || str[idx] > 126)
		{
			div = (unsigned char)str[idx] / 16;
			mod = (unsigned char)str[idx] % 16;
			ft_putchar('\\');
			ft_putchar(hex[div]);
			ft_putchar(hex[mod]);
		}
		else
		{
			ft_putchar(str[idx]);
		}
		idx++;
	}
}
