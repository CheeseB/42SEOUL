/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setblock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 14:52:06 by seongkim          #+#    #+#             */
/*   Updated: 2020/02/04 16:29:00 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		**set_real(void)
{
	int	**realblock;
	int	i;
	int	j;

	i = 0;
	realblock = (int **)malloc(sizeof(int *) * 4);
	while (i < 4)
	{
		realblock[i] = (int *)malloc(sizeof(int) * 4);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			realblock[i][j] = 0;
			j++;
		}
		i++;
	}
	// free(realblock);
	return (realblock);
}

int		**set_see(char *argv)
{
	int	**seeblock;
	int	i;
	int	j;

	i = 0;
	seeblock = (int **)malloc(sizeof(int *) * 4);
	while (i < 4)
	{
		seeblock[i] = (int *)malloc(sizeof(int) * 4);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			seeblock[i][j] = argv[(2 * j) + (i * 8)] - '0';
			j++;
		}
		i++;
	}
	// free(seeblock);
	return (seeblock);
}
