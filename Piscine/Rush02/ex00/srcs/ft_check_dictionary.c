/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dictionary.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinlee <jinlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:38:00 by jinlee            #+#    #+#             */
/*   Updated: 2020/02/09 23:22:31 by jinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_check_dictionary.h"

t_error_line		dict_process_line(char *line, int len)
{
	int idx;

	idx = 0;
	line[len] = '\0';
	if (line[idx] == '\n')
		return (EMPTY_LINE);
	while (is_number(line[idx]))
		idx++;
	if (idx == 0 || idx >= len)
		return (EMPTY_LINE);
	while (is_space(line[idx]))
		idx++;
	if (line[idx] != ':')
		return (SEP_ERROR);
	while (is_space(line[idx]))
		idx++;
	while (line[idx] != '\n' && line[idx])
	{
		if (!is_printable(line[idx]))
			return (NOT_PRINTABLE);
		idx++;
	}
	return (PROCESS_OK);
}

void				dict_count_read_line(int fd, int *cnt, t_error *error)
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
				*cnt = *cnt + 1;
			len = 0;
		}
	}
	if (file_read == -1)
		*error = READ_ERR;
	else if (file_read == 0)
		*error = REACH_EOF;
}

int					dict_count_valid_line(char *path)
{
	int			fd;
	int			cnt;
	t_error		error;

	cnt = 0;
	error = VALID;
	if ((fd = open(path, O_RDONLY)) > 0)
	{
		dict_count_read_line(fd, &cnt, &error);
		if (error != REACH_EOF)
			return (error);
	}
	if (fd == -1)
		return (OPEN_ERR);
	if (close(fd) == -1)
		return (INVALID);
	return (cnt);
}
