/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:25:27 by seongkim          #+#    #+#             */
/*   Updated: 2020/02/12 23:37:25 by jiyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_process_main.h"

t_map	init_struct(void)
{
	t_map result;

	result.row = 0;
	result.col = 0;
	result.empty = 0;
	result.fill = 0;
	result.obst = 0;
	result.map = NULL;
	result.num_map = NULL;
	return (result);
}
