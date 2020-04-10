/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeocho <yeocho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 14:59:26 by seongkim          #+#    #+#             */
/*   Updated: 2020/02/02 19:25:07 by yeocho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	input_4updown(int **realblock, int i, int j)
{
	int input;

	input = 1;
	if (i == 0)
	{
		i = 0;
		while (i < 4)
		{
			realblock[i][j] = input;
			input++;
			i++;
		}
	}
	else if (i == 1)
	{
		i = 3;
		while (i >= 0)
		{
			realblock[i][j] = input;
			input++;
			i--;
		}
	}
}

void	input_4leftright(int **realblock, int i, int j)
{
	int input;

	input = 1;
	if (i == 2)
	{
		i = j;
		j = 0;
		while (j < 4)
		{
			realblock[i][j] = input;
			input++;
			j++;
		}
	}
	else if (i == 3)
	{
		i = j;
		j = 3;
		while (j >= 0)
		{
			realblock[i][j] = input;
			input++;
			j--;
		}
	}
}

void	input_1(int **realblock, int i, int j)
{
	if (i == 0)
		realblock[0][j] = 4;
	else if (i == 1)
		realblock[3][j] = 4;
	else if (i == 2)
		realblock[j][0] = 4;
	else if (i == 3)
		realblock[j][3] = 4;
}

void	input_23(int **seeblock, int **realblock, int i, int j)
{
	if (i == 0)
	{
		if (seeblock[i][j] == 2 && seeblock[i + 1][j] == 3)
			realblock[1][j] = 4;
		else if (seeblock[i][j] == 3 && seeblock[i + 1][j] == 2)
			realblock[2][j] = 4;
	}
	else if (i == 2)
	{
		if (seeblock[i][j] == 2 && seeblock[i + 1][j] == 3)
			realblock[j][1] = 4;
		else if (seeblock[i][j] == 3 && seeblock[i + 1][j] == 2)
			realblock[j][2] = 4;
	}
}

void	input_12(int **seeblock, int **realblock, int i, int j)
{
	if (i == 0)
	{
		if (seeblock[i][j] == 1 && seeblock[i + 1][j] == 2)
			realblock[3][j] = 3;
		else if (seeblock[i][j] == 2 && seeblock[i + 1][j] == 1)
			realblock[0][j] = 3;
	}
	else if (i == 2)
	{
		if (seeblock[i][j] == 1 && seeblock[i + 1][j] == 2)
			realblock[j][3] = 3;
		else if (seeblock[i][j] == 2 && seeblock[i + 1][j] == 1)
			realblock[j][0] = 3;
	}
}
