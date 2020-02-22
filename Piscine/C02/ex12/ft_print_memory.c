/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 10:23:00 by seongkim          #+#    #+#             */
/*   Updated: 2020/01/30 14:25:52 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_address(long long address)
{
	char	*hex;
	char	print_hex[16];
	int		idx;
	int		i;

	hex = "0123456789abcdef";
	i = 0;
	while (i < 16)
	{
		idx = address % 16;
		print_hex[i] = hex[idx];
		address /= 16;
		i++;
	}
	while (i > 0)
	{
		i--;
		ft_putchar(print_hex[i]);
	}
	ft_putchar(':');
	ft_putchar(' ');
}

void	print_hex_content(unsigned char *content, unsigned int size)
{
	int				div;
	int				mod;
	unsigned int	idx;
	char			*hex;

	hex = "0123456789abcdef";
	idx = 0;
	while (idx < 16)
	{
		if (idx < size)
		{
			div = content[idx] / 16;
			mod = content[idx] % 16;
			ft_putchar(hex[div]);
			ft_putchar(hex[mod]);
		}
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		if (idx % 2 == 1)
			ft_putchar(' ');
		idx++;
	}
}

void	print_content(unsigned char *content, unsigned int size)
{
	unsigned int	idx;

	idx = 0;
	while (idx < 16)
	{
		if (idx < size)
		{
			if (content[idx] < 33 || content[idx] == 127)
				ft_putchar('.');
			else
				ft_putchar(content[idx]);
		}
		else
		{
			ft_putchar(' ');
		}
		idx++;
	}
	ft_putchar('\n');
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*content;
	long long		address;

	if (size == 0)
	{
		return (addr);
	}
	address = (long long)addr;
	content = addr;
	print_address(address);
	print_hex_content(content, size);
	print_content(content, size);
	return (addr);
}
