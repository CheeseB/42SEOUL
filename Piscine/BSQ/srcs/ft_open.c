/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:57:35 by jiyang            #+#    #+#             */
/*   Updated: 2020/02/13 01:58:27 by jiyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_open.h"
#include "ft_macro.h"
#include "ft_split.h"
#include "ft_process_main.h"

char	**file_open_read(char *file)
{
	char			**strs;
	char			*str;
	int				fd;
	unsigned int	len;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	if ((str = (char *)malloc(sizeof(char) * MAX_READ_LEN)) == NULL)
		return (0);
	len = read(fd, str, MAX_READ_LEN);
	if (len == 0)
	{
		free(str);
		return (0);
	}
	str[len] = '\0';
	if (str[len - 1] != '\n')
	{
		free(str);
		return (0);
	}
	strs = ft_split(str, "\n");
	free(str);
	return (strs);
}
