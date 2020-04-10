/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:14:45 by seongkim          #+#    #+#             */
/*   Updated: 2020/01/23 19:38:39 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	put_number(int n1, int n2, int n3);
void	loop(int n1, int n2, int n3);
void	ft_print_comb(void);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	put_number(int n1, int n2, int n3)
{
	ft_putchar(n1 + '0');
	ft_putchar(n2 + '0');
	ft_putchar(n3 + '0');
}

void	loop(int n1, int n2, int n3)
{
	while (n1 < 8)
	{
		while (n2 < 9)
		{
			while (n3 < 10)
			{
				if (n1 < n2 && n2 < n3)
				{
					put_number(n1, n2, n3);
					if (n1 == 7 && n2 == 8 && n3 == 9)
					{
						break ;
					}
					ft_putchar(',');
					ft_putchar(' ');
				}
				n3++;
			}
			n2++;
			n3 = 0;
		}
		n1++;
		n2 = 0;
		n3 = 0;
	}
}

void	ft_print_comb(void)
{
	int	num_1;
	int	num_2;
	int	num_3;

	num_1 = 0;
	num_2 = 0;
	num_3 = 0;
	loop(num_1, num_2, num_3);
}
