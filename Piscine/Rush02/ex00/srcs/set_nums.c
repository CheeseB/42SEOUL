/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nums.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinlee <jinlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:13:38 by seongkim          #+#    #+#             */
/*   Updated: 2020/02/09 23:29:55 by jinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "search_print_dict.h"
#include <stdlib.h>

extern int	g_height;

char	**malloc_input(void)
{
	int		i;
	char	**nums;

	i = 0;
	nums = (char **)malloc(sizeof(char *) * g_height);
	while (i < g_height - 1)
	{
		nums[i] = (char *)malloc(sizeof(char) * 4);
		i++;
	}
	nums[i] = 0;
	return (nums);
}

void	input_argv(char **nums, char *argv, int mod)
{
	int	i;
	int	j;
	int	idx;

	i = 0;
	idx = 0;
	while (i < g_height - 1)
	{
		j = 0;
		while (j < 3)
		{
			if (mod != 0 && i == 0 && j < 3 - mod)
				nums[i][j] = '0';
			else
			{
				nums[i][j] = argv[idx];
				idx++;
			}
			j++;
		}
		nums[i][j] = '\0';
		i++;
	}
}

void	free_nums(char **nums)
{
	int	i;

	i = 0;
	while (i < g_height)
	{
		free(nums[i]);
		i++;
	}
	free(nums);
}
