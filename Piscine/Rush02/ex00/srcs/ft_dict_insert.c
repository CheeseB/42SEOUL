/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinlee <jinlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:08:16 by jinlee            #+#    #+#             */
/*   Updated: 2020/02/09 23:22:41 by jinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict_insert.h"

int		dict_check_key_len(char *keystr)
{
	int len;

	len = 0;
	while (keystr[len])
		len++;
	return (len);
}

int		dict_check_val_len(char *valstr)
{
	int len;

	len = 0;
	while (valstr[len])
		len++;
	while (is_space(valstr[len]))
		len--;
	return (len);
}

void	ft_str_duplicate(char *dictval, char *str, int len)
{
	int idx;

	idx = 0;
	while (idx < len)
	{
		dictval[idx] = str[idx];
		idx++;
	}
	dictval[idx] = '\0';
}

void	dict_insert_keynval(t_dict_entry *entry, char *key, char *val)
{
	int len;

	len = 0;
	while (key[len])
		len++;
	ft_str_duplicate(entry->key, key, len);
	len = 0;
	while (val[len])
		len++;
	while (is_space(val[len]))
		len--;
	ft_str_duplicate(entry->value, val, len);
}
