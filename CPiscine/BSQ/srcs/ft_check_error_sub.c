/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error_sub.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:33:11 by seongkim          #+#    #+#             */
/*   Updated: 2020/02/13 08:19:45 by jiyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_macro.h"

int	check_is_repeated(char *info, int info_leng)
{
	if (info[info_leng - 3] == info[info_leng - 2])
		return (1);
	if (info[info_leng - 2] == info[info_leng - 1])
		return (1);
	if (info[info_leng - 1] == info[info_leng - 3])
		return (1);
	return (0);
}

int	check_is_printable(char info)
{
	if (info >= MIN_PRINTABLE_CHAR && info <= MAX_PRINTABLE_CHAR)
		return (1);
	else
		return (0);
}

int	check_map_valid(char **map, int row_len, int col_len, char *info_box)
{
	int	i;
	int	j;

	i = 0;
	while (++i < row_len)
	{
		j = -1;
		while (++j < col_len)
		{
			if (map[i][j] == info_box[0] || map[i][j] == info_box[1])
				continue ;
			else
				return (0);
		}
	}
	return (1);
}
