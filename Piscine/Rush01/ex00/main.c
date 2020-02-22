/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 16:53:43 by seongkim          #+#    #+#             */
/*   Updated: 2020/02/04 16:30:04 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		check_error1(int argc, char *argv)
{
	int	idx;
	int	num;

	idx = 0;
	num = 0;
	if (argc != 2)
		return (0);
	while (argv[idx])
	{
		if (idx % 2)
		{
			if (argv[idx] != ' ')
				return (0);
		}
		else
		{
			if (!(argv[idx] >= '1' && argv[idx] <= '4'))
				return (0);
			num++;
		}
		idx++;
	}
	if (!(idx == 31 && num == 16))
		return (0);
	return (1);
}

int		check_error2(char *argv)
{
	int	i;
	int	j;

	j = 0;
	while (j < 2)
	{
		i = 0;
		while (i < 4)
		{
			if (argv[(j * 16) + (2 * i)] +
				argv[(j * 16) + (2 * i) + 8] < '3' + '0'
				|| argv[(j * 16) + (2 * i)] +
				argv[(j * 16) + (2 * i) + 8] > '5' + '0')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

void	certain_num_input(int **seeblock, int **realblock)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (seeblock[i][j] == 1)
				input_1(realblock, i, j);
			if (seeblock[i][j] == 4)
			{
				input_4leftright(realblock, i, j);
				input_4updown(realblock, i, j);
			}
			if (seeblock[i][j] == 2 || seeblock[i][j] == 3)
				input_23(seeblock, realblock, i, j);
			if (seeblock[i][j] == 1 || seeblock[i][j] == 2)
				input_12(seeblock, realblock, i, j);
			j++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	int **realblock;
	int	**seeblock;
	int	i;

	i = 0;
	if (check_error1(argc, argv[1]) && check_error2(argv[1]))
	{
		realblock = set_real();
		seeblock = set_see(argv[1]);
		certain_num_input(seeblock, realblock);
		dfs(0, 0, 0, realblock);
		print_block(realblock);
	}
	else
		write(1, "Error\n", 6);
	return (0);
	free(realblock);
	free(seeblock);
}
