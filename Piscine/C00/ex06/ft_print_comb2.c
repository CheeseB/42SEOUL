/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:48:54 by seongkim          #+#    #+#             */
/*   Updated: 2020/01/23 20:46:50 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	print_num(int n1, int n2);
void	ft_print_comb2(void);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_num(int n1, int n2)
{
	char num1_10;
	char num1_1;
	char num2_10;
	char num2_1;

	num1_10 = (n1 / 10) + '0';
	num1_1 = (n1 % 10) + '0';
	num2_10 = (n2 / 10) + '0';
	num2_1 = (n2 % 10) + '0';
	ft_putchar(num1_10);
	ft_putchar(num1_1);
	ft_putchar(' ');
	ft_putchar(num2_10);
	ft_putchar(num2_1);
	if (n1 != 98 || n2 != 99)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int	num_1;
	int	num_2;

	num_1 = 0;
	num_2 = 0;
	while (num_1 < 99)
	{
		while (num_2 < 100)
		{
			if (num_1 != num_2)
			{
				print_num(num_1, num_2);
			}
			num_2++;
		}
		if (num_1 != 98)
		{
			ft_putchar(' ');
		}
		num_1++;
		num_2 = 0;
	}
}
