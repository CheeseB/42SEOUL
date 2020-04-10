/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_dictionary.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinlee <jinlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:09:58 by jinlee            #+#    #+#             */
/*   Updated: 2020/02/09 23:22:55 by jinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_free_dictionary.h"

void	ft_free_dictionary(t_dict dict)
{
	int idx;

	idx = 0;
	while (idx < dict.size)
	{
		free(dict.entries[idx].key);
		free(dict.entries[idx].value);
		idx++;
	}
	free(dict.entries);
}
