/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:02:35 by seongkim          #+#    #+#             */
/*   Updated: 2020/01/23 16:11:51 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n);

void	ft_is_negative(int n)
{
	char char_p;
	char char_n;

	char_p = 'P';
	char_n = 'N';
	if (n < 0)
	{
		write(1, &char_n, 1);
	}
	else
	{
		write(1, &char_p, 1);
	}
}
