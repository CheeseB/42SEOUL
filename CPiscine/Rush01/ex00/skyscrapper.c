/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscrapper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 17:10:07 by sungslee          #+#    #+#             */
/*   Updated: 2020/02/04 16:33:36 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	g_flag;

int		check_col(int **realblock)
{
	int selected[5];
	int index;
	int col;

	col = 0;
	while (col < 4)
	{
		index = 1;
		while (index <= 4)
			selected[index++] = 0;
		index = 0;
		while (index < 4)
		{
			if (selected[realblock[index][col]] != 0)
				return (0);
			selected[realblock[index][col]] = 1;
			index++;
		}
		col++;
	}
	return (1);
}

int		check_row(int end, int **realblock)
{
	int selected[5];
	int index;
	int row;

	row = end;
	while (row <= end)
	{
		index = 1;
		while (index <= 4)
			selected[index++] = 0;
		index = 0;
		while (index < 4)
		{
			if (selected[realblock[row][index]] == 1)
				return (0);
			selected[realblock[row][index]] = 1;
			index++;
		}
		row++;
	}
	return (1);
}

int		check_answer(int depth, int **realblock)
{
	if (depth == 16)
	{
		if (check_col(realblock))
			g_flag = 1;
		return (0);
	}
	return (1);
}

void	dfs(int depth, int row, int col, int **realblock)
{
	int num;

	if (g_flag || !(check_answer(depth, realblock)))
		return ;
	if (col == 4)
	{
		if (check_row(row, realblock))
			dfs(depth, row + 1, 0, realblock);
		else
			return ;
	}
	num = 1;
	while (num <= 4)
	{
		if (realblock[row][col] != 0)
			dfs(depth + 1, row, col + 1, realblock);
		else
		{
			realblock[row][col] = num;
			dfs(depth + 1, row, col + 1, realblock);
			if (!g_flag)
				realblock[row][col] = 0;
		}
		num++;
	}
}
