/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_dictionary.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinlee <jinlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 12:25:42 by jinlee            #+#    #+#             */
/*   Updated: 2020/02/09 23:23:15 by jinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_load_dictionary.h"

void	dict_insert_line(t_dict_entry *entry, char *line, int cnt)
{
	int		idx;
	int		len;
	char	**split_str;

	idx = 0;
	len = 0;
	split_str = ft_split(line, ":");
	len = dict_check_key_len(split_str[0]);
	entry[cnt].length = (unsigned int)len;
	entry[cnt].comma_cnt = (unsigned int)(len - 1) / 3;
	entry[cnt].key = (char *)malloc(sizeof(char) * (len + 1));
	len = dict_check_val_len(split_str[1]);
	entry[cnt].value = (char *)malloc(sizeof(char) * (len + 1));
	dict_insert_keynval(&entry[cnt], split_str[0], split_str[1]);
}

void	dict_parse(int fd, t_dict_entry *entry, int *cnt, t_error *error)
{
	char	buffer[0];
	char	line[100];
	int		file_read;
	int		len;

	len = 0;
	while ((file_read = read(fd, buffer, 1)) > 0)
	{
		line[len] = buffer[0];
		len++;
		if (buffer[0] == '\n')
		{
			if (dict_process_line(line, len))
			{
				dict_insert_line(entry, line, *cnt);
				*cnt = *cnt + 1;
			}
			len = 0;
		}
	}
	if (file_read == -1)
		*error = READ_ERR;
	else if (file_read == 0)
		*error = REACH_EOF;
}

t_bool	dict_load_valid_line(char *path, t_dict *dict)
{
	int				fd;
	int				cnt;
	t_dict_entry	*entries;
	t_error			error;

	error = VALID;
	cnt = 0;
	if ((fd = open(path, O_RDONLY)) < 0)
		return (FALSE);
	entries = dict->entries;
	dict_parse(fd, entries, &cnt, &error);
	if (error != REACH_EOF)
		return (FALSE);
	if (close(fd) == -1)
		return (FALSE);
	return (TRUE);
}

t_dict	ft_load_dictionary(char *path)
{
	int				size;
	t_dict_entry	*entries;
	t_dict			dict;

	dict = (t_dict){path, FALSE, 0, 0};
	size = dict_count_valid_line(path);
	if (size == INVALID)
		return (dict);
	if (!(entries = malloc(sizeof(t_dict_entry) * (size + 1))))
		return (dict);
	entries[size].length = 0;
	dict.size = size;
	dict.entries = entries;
	dict.valid = dict_load_valid_line(path, &dict);
	if (dict.valid)
		dict_entry_sort(&dict);
	return (dict);
}

t_dict	ft_load_default_dictionary(void)
{
	return (ft_load_dictionary(ENG_DICT));
}
