/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:47:37 by jiyang            #+#    #+#             */
/*   Updated: 2020/02/12 14:55:50 by jiyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void	display_error(int argc, int i)
{
	int		idx;
	char	*str;

	idx = 0;
	str = "map error\n";
	while (str[idx])
	{
		write(1, &str[idx], 1);
		idx++;
	}
	if (argc - 1 != i)
		write(1, "\n", 1);
}

void	print_str(char *str)
{
	int		idx;

	idx = 0;
	while (str[idx])
	{
		write(1, &str[idx], 1);
		idx++;
	}
}
