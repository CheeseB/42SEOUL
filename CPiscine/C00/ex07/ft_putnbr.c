/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:27:52 by seongkim          #+#    #+#             */
/*   Updated: 2020/01/24 11:17:26 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	loop(int nt, int leng, int nb_);
void	ft_putnbr(int nb);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	loop(int nt, int leng, int nb_)
{
	while (nt / leng)
	{
		leng *= 10;
	}
	leng /= 10;
	if (nb_ < 0)
	{
		ft_putchar('-');
	}
	while (nb_)
	{
		nt = (nb_ / leng);
		if (nt < 0)
		{
			nt *= -1;
		}
		ft_putchar(nt + '0');
		nb_ %= leng;
		leng /= 10;
	}
}

void	ft_putnbr(int nb)
{
	int	num_temp;
	int	length;

	length = 1;
	num_temp = nb;
	if (nb == 0)
	{
		ft_putchar('0');
	}
	else
	{
		loop(num_temp, length, nb);
	}
}
