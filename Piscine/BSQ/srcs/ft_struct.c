/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:16:10 by jiyang            #+#    #+#             */
/*   Updated: 2020/02/11 17:47:37 by jiyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_manage_str.h"
#include "ft_struct.h"

int		**num_value_insert(char **info, char obst, char empty)
{
	int	row_len;
	int	col_len;
	int	**num_map;
	int	i;
	int j;

	i = -1;
	row_len = ft_strslen(info) - 1;
	col_len = ft_strlen(info[1]);
	num_map = (int **)malloc(sizeof(int *) * row_len);
	while (++i < row_len)
		num_map[i] = (int *)malloc(sizeof(int) * col_len);
	i = -1;
	while (++i < row_len)
	{
		j = -1;
		while (++j < col_len)
		{
			if (info[i + 1][j] == obst)
				num_map[i][j] = 0;
			else if (info[i + 1][j] == empty)
				num_map[i][j] = 1;
		}
	}
	return (num_map);
}

t_map	ft_value_insert(t_map res, char **info)
{
	int		len;

	len = ft_strlen(info[0]);
	res.row = ft_strslen(info) - 1;
	res.col = ft_strlen(info[1]);
	res.empty = info[0][len - 3];
	res.obst = info[0][len - 2];
	res.fill = info[0][len - 1];
	res.map = info;
	res.num_map = num_value_insert(info, res.obst, res.empty);
	return (res);
}
