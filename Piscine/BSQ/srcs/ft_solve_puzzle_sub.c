/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_puzzle_sub.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 21:14:15 by seongkim          #+#    #+#             */
/*   Updated: 2020/02/13 01:44:20 by jiyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solve_puzzle.h"
#include <stdio.h>

void	ft_put_square(t_map problem, int row, int col, int max)
{
	int	i;
	int	j;
	int	limit_row;
	int	limit_col;

	limit_row = row - max + 2;
	limit_col = col - max + 1;
	i = row + 2;
	while (--i >= limit_row)
	{
		j = col + 1;
		while (--j >= limit_col)
			problem.map[i][j] = problem.fill;
	}
	i = 0;
	limit_row = problem.row + 1;
	while (++i < limit_row)
	{
		write(1, problem.map[i], problem.col);
		print_str("\n");
	}
}

void	ft_find_min_location(t_map problem, int max)
{
	int	row;
	int	flag;
	int	col;
	int	xy[2];

	row = -1;
	flag = 0;
	while (++row < problem.row)
	{
		col = -1;
		while (++col < problem.col)
		{
			if (max == problem.num_map[row][col])
			{
				xy[0] = row;
				xy[1] = col;
				flag = 1;
				break ;
			}
		}
		if (flag)
			break ;
	}
	ft_put_square(problem, xy[0], xy[1], max);
}
