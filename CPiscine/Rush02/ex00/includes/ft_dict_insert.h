/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_insert.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinlee <jinlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:16:42 by jinlee            #+#    #+#             */
/*   Updated: 2020/02/09 19:51:00 by jinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DICT_INSERT_H
# define FT_DICT_INSERT_H

# include "ft_check_dictionary.h"
# include "ft_is_check.h"

int		dict_check_key_len(char *keystr);
int		dict_check_val_len(char *valstr);
void	ft_str_duplicate(char *dictval, char *str, int len);
void	dict_insert_keynval(t_dict_entry *entry, char *key, char *val);

#endif
