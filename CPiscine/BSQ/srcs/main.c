/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 08:59:20 by seongkim          #+#    #+#             */
/*   Updated: 2020/02/13 08:35:29 by jiyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_open.h"
#include "ft_free.h"
#include "ft_struct.h"
#include "ft_print.h"
#include "ft_macro.h"
#include "ft_split.h"
#include "ft_manage_str.h"
#include "ft_check_error.h"
#include "ft_solve_puzzle.h"
#include "ft_process_main.h"

int		check_stdin_error(int size, char *str)
{
	if (size == 0)
	{
		free(str);
		display_error(1, 0);
		return (1);
	}
	if (str[size - 1] != '\n')
	{
		free(str);
		display_error(1, 0);
		return (1);
	}
	return (0);
}

char	*read_stdin(void)
{
	char	*str;
	char	*buf;
	int		size;

	if ((str = (char *)malloc(sizeof(char) * MAX_READ_LEN)) == NULL)
		return (0);
	if ((buf = (char *)malloc(sizeof(char) * MAX_READ_LEN)) == NULL)
	{
		if (str != NULL)
			free(str);
		return (0);
	}
	while ((size = read(0, buf, MAX_READ_LEN)))
	{
		buf[size] = 0;
		str = ft_strdup_cat(str, buf);
	}
	free(buf);
	return (str);
}

void	stdin_map(void)
{
	int		size;
	char	*str;
	t_map	result;
	char	**info_map;

	str = read_stdin();
	if (str == 0)
		return ;
	size = ft_strlen(str);
	if (check_stdin_error(size, str))
		return ;
	info_map = ft_split(str, "\n");
	free(str);
	result = init_struct();
	if (!info_map || check_error(info_map))
	{
		ft_free_and_error(info_map, 1, 0);
		return ;
	}
	result = ft_value_insert(result, info_map);
	ft_solve_puzzle(result, 1, 0);
	ft_whole_free(result.map, result.num_map, result.row);
}

int		main(int argc, char **argv)
{
	int		i;
	t_map	result;
	char	**info_map;

	if (argc == 1)
		stdin_map();
	else
	{
		i = 0;
		while (++i < argc)
		{
			result = init_struct();
			info_map = file_open_read(argv[i]);
			if (!info_map || check_error(info_map))
			{
				display_error(argc, i);
				ft_strs_free(info_map);
				continue ;
			}
			result = ft_value_insert(result, info_map);
			ft_solve_puzzle(result, argc, i);
			ft_whole_free(result.map, result.num_map, result.row);
		}
	}
	return (0);
}
