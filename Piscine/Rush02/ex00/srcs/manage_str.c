/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinlee <jinlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:08:50 by seongkim          #+#    #+#             */
/*   Updated: 2020/02/09 23:34:13 by jinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "search_print_dict.h"

int		str_length(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

int		my_strcmp(char *str1, char *str2)
{
	int	sub;
	int	i;
	int	j;

	sub = 0;
	i = 0;
	j = 0;
	while (str1[i] || str2[j])
	{
		sub = str1[i] - str2[j];
		if (sub != 0)
			return (1);
		if (str1[i] != 0)
			i++;
		if (str2[j] != 0)
			j++;
	}
	return (0);
}

void	print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		write(1, &str[i], 1);
		i++;
	}
}
