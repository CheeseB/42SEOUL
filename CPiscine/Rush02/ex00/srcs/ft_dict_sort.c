/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinlee <jinlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 20:12:53 by jinlee            #+#    #+#             */
/*   Updated: 2020/02/09 23:22:51 by jinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict_sort.h"

void	dict_entry_swap(t_dict *dict, int i, int j)
{
	t_dict_entry	temp;

	temp = dict->entries[i];
	dict->entries[i] = dict->entries[j];
	dict->entries[j] = temp;
}

int		dict_entry_key_comp(t_dict *dict, int i, int j)
{
	unsigned int idx;

	idx = 0;
	while (idx < dict->entries[i].length)
	{
		if (dict->entries[i].key[idx] < dict->entries[j].key[idx])
			return (0);
		else if (dict->entries[i].key[idx] > dict->entries[j].key[idx])
		{
			return (1);
		}
		idx++;
	}
	return (0);
}

void	dict_entry_sort(t_dict *dict)
{
	int i;
	int j;

	i = 0;
	while (i < dict->size)
	{
		j = i + 1;
		while (j < dict->size)
		{
			if (dict->entries[i].length > dict->entries[j].length)
				dict_entry_swap(dict, i, j);
			else if (dict->entries[i].length == dict->entries[j].length)
			{
				if (dict_entry_key_comp(dict, i, j))
					dict_entry_swap(dict, i, j);
			}
			j++;
		}
		i++;
	}
}
