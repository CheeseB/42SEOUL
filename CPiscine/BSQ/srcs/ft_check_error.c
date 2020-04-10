/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:51:19 by seongkim          #+#    #+#             */
/*   Updated: 2020/02/12 13:14:34 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_macro.h"
#include "ft_manage_str.h"
#include "ft_check_error.h"

int	check_info_error(char *info, int *info_row_len, char *info_box)
{
	int	info_leng;
	int	i;
	int	idx;

	info_leng = ft_strlen(info);
	if (info_leng < MIN_INFO_LENGTH)
		return (1);
	i = 0;
	while (i < info_leng - CHAR_INFO_LENGTH)
	{
		if (info[i] < '0' || info[i] > '9')
			return (1);
		*info_row_len = (*info_row_len * 10) + (info[i] - '0');
		i++;
	}
	idx = 0;
	while (i < info_leng)
	{
		if (!check_is_printable(info[i]))
			return (1);
		info_box[idx++] = info[i++];
	}
	if (check_is_repeated(info, info_leng))
		return (1);
	return (0);
}

int	check_map_error(char **map, int info_row_len, char *info_box)
{
	int	row_len;
	int	col_len;
	int	i;

	row_len = ft_strslen(map);
	if (row_len < 2 || row_len - 1 != info_row_len)
		return (1);
	col_len = ft_strlen(map[1]);
	i = 2;
	while (i < row_len)
	{
		if (col_len != ft_strlen(map[i]))
			return (1);
		col_len = ft_strlen(map[i]);
		i++;
	}
	if (!check_map_valid(map, row_len, col_len, info_box))
		return (1);
	return (0);
}

int	check_error(char **map_file)
{
	int		info_row_len;
	char	info_box[3];

	info_row_len = 0;
	if (check_info_error(map_file[0], &info_row_len, info_box))
		return (1);
	if (check_map_error(map_file, info_row_len, info_box))
		return (1);
	return (0);
}
