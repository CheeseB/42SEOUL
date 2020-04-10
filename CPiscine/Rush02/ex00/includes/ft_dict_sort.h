/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_sort.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinlee <jinlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 20:12:34 by jinlee            #+#    #+#             */
/*   Updated: 2020/02/09 20:24:19 by jinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DICT_SORT_H
# define FT_DICT_SORT_H

# include "ft_check_dictionary.h"

void	dict_entry_swap(t_dict *dict, int i, int j);
int		dict_entry_key_comp(t_dict *dict, int i, int j);
void	dict_entry_sort(t_dict *dict);

#endif
