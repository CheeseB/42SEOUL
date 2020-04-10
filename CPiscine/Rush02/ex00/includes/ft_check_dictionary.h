/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dictionary.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinlee <jinlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:34:37 by jinlee            #+#    #+#             */
/*   Updated: 2020/02/09 21:39:07 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECK_DICTIONARY_H
# define FT_CHECK_DICTIONARY_H

# include <fcntl.h>
# include <unistd.h>
# include "ft_is_check.h"

typedef enum
{
	INVALID = 0,
	VALID = 1,
	OPEN_ERR = 0,
	READ_ERR = 0,
	REACH_EOF = 1
}	t_error;
typedef enum
{
	EMPTY_LINE = 0,
	NOT_PRINTABLE = 0,
	SEP_ERROR = 0,
	PROCESS_OK = 1
}	t_error_line;
typedef struct		s_dict_entry
{
	unsigned int	length;
	unsigned int	comma_cnt;
	char			*key;
	char			*value;
}					t_dict_entry;
typedef struct		s_dict
{
	char			*path;
	t_bool			valid;
	int				size;
	t_dict_entry	*entries;
}					t_dict;

t_error_line		dict_process_line(char *line, int len);
void				dict_count_read_line(int fd, int *cnt, t_error *error);
int					dict_count_valid_line(char *path);

#endif
