/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_dict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinlee <jinlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:22:19 by seongkim          #+#    #+#             */
/*   Updated: 2020/02/09 23:29:45 by jinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "search_print_dict.h"

char	*search_dict_digit(t_dict_entry dict[], int digit)
{
	int	i;

	i = 0;
	while (dict[i].length != 0)
	{
		if (dict[i].comma_cnt == (unsigned int)digit)
			return (dict[i].value);
		i++;
	}
	print_str("Dict Error\n");
	return (0);
}

char	*search_dict_key(t_dict_entry dict[], char *key)
{
	int	i;

	i = 0;
	while (dict[i].length != 0)
	{
		if (my_strcmp(dict[i].key, key) == 0)
			return (dict[i].value);
		i++;
	}
	print_str("Dict Error\n");
	return (0);
}
