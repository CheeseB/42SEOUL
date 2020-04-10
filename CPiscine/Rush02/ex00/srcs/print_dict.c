/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinlee <jinlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:24:12 by seongkim          #+#    #+#             */
/*   Updated: 2020/02/09 23:36:39 by jinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "search_print_dict.h"
#include <stdio.h>

extern int	g_height;

void	print_nums(t_dict_entry dict[], char **nums, int div, int mod)
{
	int		i;
	int		digit;
	char	*digit_value;

	i = -1;
	if (mod == 0)
		digit = div - 1;
	else
		digit = div;
	while (++i < g_height - 1)
	{
		if (my_strcmp(nums[i], "000") != 0)
		{
			print_hundreds(dict, nums[i]);
			digit_value = search_dict_digit(dict, digit);
			print_str(digit_value);
		}
		digit--;
	}
}

void	print_value(t_dict_entry dict[], char c[], int idx)
{
	char	*key_value;

	key_value = search_dict_key(dict, c);
	print_str(key_value);
	if (idx == 0)
	{
		key_value = search_dict_key(dict, "100");
		print_str(key_value);
	}
}

void	c_init(char c[])
{
	int	i;

	i = 0;
	while (i < 3)
	{
		c[i] = '\0';
		i++;
	}
}

void	print_hundreds(t_dict_entry dict[], char *nums_row)
{
	int		idx;
	char	c[3];

	c_init(c);
	idx = -1;
	while (++idx < 3)
	{
		if (nums_row[idx] != '0')
		{
			c[0] = nums_row[idx];
			if (idx == 1 && nums_row[idx] == '1')
			{
				c[1] = nums_row[idx + 1];
				print_value(dict, c, idx);
				break ;
			}
			else if (idx == 1 && nums_row[idx] != '1')
				c[1] = '0';
			print_value(dict, c, idx);
		}
		c_init(c);
	}
}
