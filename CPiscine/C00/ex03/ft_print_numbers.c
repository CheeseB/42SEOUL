/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:53:25 by seongkim          #+#    #+#             */
/*   Updated: 2020/01/23 15:59:37 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void);

void	ft_print_numbers(void)
{
	int		num;
	char	num_char;

	num = 0;
	while (num < 10)
	{
		num_char = num + '0';
		write(1, &num_char, 1);
		num++;
	}
}
