/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_dictionary.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinlee <jinlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 12:25:44 by jinlee            #+#    #+#             */
/*   Updated: 2020/02/09 21:01:12 by jinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LOAD_DICTIONARY_H
# define FT_LOAD_DICTIONARY_H

# define ENG_DICT "numbers.dict"
# include "ft_check_dictionary.h"
# include "ft_dict_insert.h"
# include "ft_dict_sort.h"
# include "ft_is_check.h"
# include "ft_split.h"

void		dict_insert_line(t_dict_entry *entry, char *line, int cnt);
void		dict_parse(int fd, t_dict_entry *entry, int *cnt, t_error *error);
t_bool		dict_load_valid_line(char *path, t_dict *dict);
t_dict		ft_load_dictionary(char *path);
t_dict		ft_load_default_dictionary(void);

#endif
