/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 21:19:18 by seongkim          #+#    #+#             */
/*   Updated: 2020/02/13 00:57:33 by jiyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_free.h"

void	ft_strs_free(char **strs)
{
	int	i;

	i = 0;
	if (strs == NULL)
		return ;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	ft_ints_free(int **ints, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(ints[i]);
		i++;
	}
	free(ints);
}

void	ft_whole_free(char **strs, int **ints, int row)
{
	ft_strs_free(strs);
	ft_ints_free(ints, row);
}

void	ft_free_and_error(char **strs, int argc, int idx)
{
	display_error(argc, idx);
	ft_strs_free(strs);
}
