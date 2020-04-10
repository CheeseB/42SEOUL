/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 08:04:23 by seongkim          #+#    #+#             */
/*   Updated: 2020/02/13 15:26:43 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	i;

	i = 1;
	while (i < nb / 2)
	{
		if (i * i >= nb)
			return (i);
		i++;
	}
	return (0);
}

int	ft_is_prime(int nb)
{
	int	i;
	int	nb_sqrt;

	i = 2;
	if (nb <= 1)
		return (0);
	nb_sqrt = ft_sqrt(nb);
	while (i <= nb_sqrt)
	{
		if (nb % i == 0 && nb != i)
			return (0);
		i++;
	}
	return (1);
}
