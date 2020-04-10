/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:30:25 by seongkim          #+#    #+#             */
/*   Updated: 2020/01/26 11:28:27 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	zero_init(int *arr);
void	ft_print_combn(int n);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	zero_init(int *arr)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		arr[i] = 0;
	}
}

void	ft_print_combn(int n)
{
	int		idx;
	int		start_idx;
	int		print;
	int		check[10];
	char	num_char;

	start_idx = 0;
	zero_init(check);
	while (start_idx <= 10 - n)
	{
		print = 0;
		idx = start_idx;
		while (idx < 10)
		{
			if (check[idx] == 0)
			{
				num_char = idx + '0';
				ft_putchar(num_char);
				print++;
			}
			if (print == n)
			{
				if (idx == 9)
				{
					start_idx++;
					zero_init(check);
					break ;
				}
				else
				{
					check[idx] = 1;
					break ;
				}
			}
			idx++;
		}
		ft_putchar(',');
		ft_putchar(' ');
	}
}
