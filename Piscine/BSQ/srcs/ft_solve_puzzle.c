/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_puzzle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:39:50 by seongkim          #+#    #+#             */
/*   Updated: 2020/02/12 14:27:06 by jiyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solve_puzzle.h"

int		ft_find_min(int num1, int num2, int num3)
{
	int min;

	if (num1 < num2)
	{
		if (num1 < num3)
			min = num1;
		else
			min = num3;
	}
	else
	{
		if (num2 < num3)
			min = num2;
		else
			min = num3;
	}
	return (min);
}

int		ft_find_max(t_map problem)
{
	int	row;
	int	col;
	int	max;

	row = -1;
	max = -1;
	while (++row < problem.row)
	{
		col = -1;
		while (++col < problem.col)
			if (problem.num_map[row][col] > max)
				max = problem.num_map[row][col];
	}
	return (max);
}

int		**ft_solve(t_map problem)
{
	int	row;
	int	col;

	row = 0;
	while (++row < problem.row)
	{
		col = 0;
		while (++col < problem.col)
		{
			if (problem.num_map[row][col] == 0)
				continue ;
			problem.num_map[row][col] = ft_find_min(
			problem.num_map[row - 1][col],
			problem.num_map[row][col - 1],
			problem.num_map[row - 1][col - 1]) + 1;
		}
	}
	return (problem.num_map);
}

void	ft_solve_puzzle(t_map problem, int argc, int idx)
{
	int	max;

	problem.num_map = ft_solve(problem);
	max = ft_find_max(problem);
	ft_find_min_location(problem, max);
	if (idx != argc - 1)
		print_str("\n");
}
