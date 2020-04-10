/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:19:58 by seongkim          #+#    #+#             */
/*   Updated: 2020/01/23 15:32:06 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void);

void	ft_print_alphabet(void)
{
	int		i;
	char	alpha;

	i = 0;
	while (i < 26)
	{
		alpha = 'a' + i;
		write(1, &alpha, 1);
		i++;
	}
}
