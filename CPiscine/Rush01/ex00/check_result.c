/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 21:22:50 by sungslee          #+#    #+#             */
/*   Updated: 2020/02/04 16:23:46 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_arr_col(int **realblock, int **seeblock)
{
	int a;
	int b;
	int c;
	int count;

	a = -1;
	count = 0;
	while (a++ < 1)
	{
		b = -1;
		while (b++ < 3)
		{
			c = -1;
			while (c < 2)
			{
				if (realblock[c][b] - realblock[c + 1][b] < 0)
					count++;
			}
			if (count == seeblock[a][b])
				return (1);
		}
	}
	return (0);
}

int		check_arr_row(int **realblock, int **seeblock)
{
	int a;
	int b;
	int c;
	int count;

	a = 2;
	count = 0;
	while (a++ < 3)
	{
		b = -1;
		while (b < 3)
		{
			c = -1;
			while (c < 2)
			{
				if (realblock[b][c] - realblock[b][c + 1] < 0)
					count++;
			}
			if (count == seeblock[a][b])
				return (0);
		}
	}
	return (1);
}
