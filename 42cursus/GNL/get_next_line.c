/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongki@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 11:44:57 by seongkim          #+#    #+#             */
/*   Updated: 2020/07/19 22:39:41 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_strdel(char **addr)
{
	if (addr && *addr)
	{
		free(*addr);
		*addr = NULL;
	}
}

static char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;
	size_t	len;

	s1_len = 0;
	s2_len = ft_strlen(s2);
	if (s1)
		s1_len = ft_strlen(s1);
	len = s1_len + s2_len;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == 0)
		return (0);
	if (s1)
	{
		ft_strlcpy(result, s1, (s1_len + 1));
		ft_strdel(&s1);
	}
	ft_strlcpy(result + s1_len, s2, (s2_len + 1));
	return (result);
}

static int	is_newline(char **str, char **line)
{
	char	*newline;
	size_t	len;
	size_t	end;

	len = 0;
	newline = 0;
	if ((newline = ft_strchr(*str, '\n')))
	{
		end = newline - *str;
		len = ft_strlen(newline);
		*line = ft_substr(*str, 0, end);
		ft_strlcpy(*str, (newline + 1), (len + 1));
		return (NEWLINE);
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	int			bytes;
	char		buffer[BUFFER_SIZE + 1];
	static char	*str;

	if (!line || fd < 0 || BUFFER_SIZE < 1)
		return (ERROR);
	if (str && is_newline(&str, line))
		return (NEWLINE);
	while ((bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes] = '\0';
		if (!(str = ft_strjoin(str, buffer)))
			return (ERROR);
		if (is_newline(&str, line))
			return (NEWLINE);
	}
	if (str && *str)
		*line = ft_strdup(str);
	else
		*line = ft_strdup("");
	ft_strdel(&str);
	return (bytes);
}
