/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 09:56:33 by seongkim          #+#    #+#             */
/*   Updated: 2020/02/06 04:52:21 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_error(char *base, unsigned int *size)
{
	unsigned int	i;
	unsigned int	j;
	const int		error = 1;
	const int		correct = 0;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (error);
		i++;
	}
	*size = i;
	if (*size <= 1)
		return (error);
	i = 0;
	while (i < *size - 1)
	{
		j = i + 1;
		while (j < *size)
			if (base[i] == base[j++])
				return (error);
		i++;
	}
	return (correct);
}

void	print_nbr(unsigned int nbr_positive, unsigned int size, char *base)
{
	if (nbr_positive / size != 0)
		print_nbr((nbr_positive / size), size, base);
	write(1, &base[nbr_positive % size], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	size;
	unsigned int	nbr_positive;

	if (is_error(base, &size))
		return ;
	if (nbr < 0)
	{
		if (nbr == -2147483648)
			nbr_positive = 2147483648;
		else
			nbr_positive = nbr * -1;
		write(1, "-", 1);
	}
	else
		nbr_positive = nbr;
	print_nbr(nbr_positive, size, base);
}
