/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 13:35:56 by jihong            #+#    #+#             */
/*   Updated: 2020/01/26 16:24:33 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern void	ft_putchar(char c);

void		print_start_line(int x)
{
	int x_index;

	ft_putchar('/');
	x_index = 1;
	while (x_index < x - 1)
	{
		ft_putchar('*');
		x_index++;
	}
	if (x > 1)
	{
		ft_putchar('\\');
	}
	ft_putchar('\n');
}

void		print_end_line(int x)
{
	int	x_index;

	ft_putchar('\\');
	x_index = 1;
	while (x_index < x - 1)
	{
		ft_putchar('*');
		x_index++;
	}
	if (x > 1)
	{
		ft_putchar('/');
	}
	ft_putchar('\n');
}

void		print_middle_line(int x, int y)
{
	int x_index;
	int y_index;

	y_index = 1;
	while (y_index < y - 1)
	{
		ft_putchar('*');
		x_index = 1;
		while (x_index < x - 1)
		{
			ft_putchar(' ');
			x_index++;
		}
		if (x > 1)
		{
			ft_putchar('*');
		}
		ft_putchar('\n');
		y_index++;
	}
}

void		rush(int x, int y)
{
	if (x == 0 || y == 0)
	{
		return ;
	}
	print_start_line(x);
	if (y < 2)
	{
		return ;
	}
	print_middle_line(x, y);
	print_end_line(x);
}
