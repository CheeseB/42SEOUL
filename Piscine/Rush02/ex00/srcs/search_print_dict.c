/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_print_dict.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinlee <jinlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 20:47:12 by seongkim          #+#    #+#             */
/*   Updated: 2020/02/09 23:33:58 by jinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "search_print_dict.h"

int	g_height;

void	search_print_dict(t_dict_entry dict[], char *argv)
{
	int		arg_length;
	int		div;
	int		mod;
	char	**nums;

	arg_length = str_length(argv);
	div = arg_length / 3;
	mod = arg_length % 3;
	if (mod == 0)
		g_height = div + 1;
	else
		g_height = div + 2;
	nums = malloc_input();
	input_argv(nums, argv, mod);
	print_nums(dict, nums, div, mod);
	free_nums(nums);
}
