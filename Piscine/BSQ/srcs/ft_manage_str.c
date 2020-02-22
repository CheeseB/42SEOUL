/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:52:10 by seongkim          #+#    #+#             */
/*   Updated: 2020/02/13 00:47:23 by jiyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_manage_str.h"

int		ft_strslen(char **strs)
{
	int	len;

	len = 0;
	while (strs[len])
		len++;
	return (len);
}

int		ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*str_mall;
	int		i;

	i = 0;
	str_mall = (char *)malloc(ft_strlen(src) + 1);
	if (str_mall == NULL)
		return (0);
	while (src[i])
	{
		str_mall[i] = src[i];
		i++;
	}
	str_mall[i] = src[i];
	return (str_mall);
}

char	*ft_strdup_cat(char *dest, char *src)
{
	int		i;
	int		dest_len;

	i = -1;
	dest_len = ft_strlen(dest);
	while (src[++i])
		dest[dest_len + i] = src[i];
	dest[dest_len + i + 1] = 0;
	return (dest);
}
