/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:42:49 by seongkim          #+#    #+#             */
/*   Updated: 2020/01/23 15:46:16 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void);

void	ft_print_reverse_alphabet(void)
{
	int		i;
	char	alpha;

	i = 0;
	while (i < 26)
	{
		alpha = 'z' - i;
		write(1, &alpha, 1);
		i++;
	}
}
