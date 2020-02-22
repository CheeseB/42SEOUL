/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 09:55:23 by jiyang            #+#    #+#             */
/*   Updated: 2020/02/12 16:56:02 by jiyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split.h"

int		is_sep(char ch, char *sep)
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	while (sep[++i])
		if (sep[i] == ch)
			res = 1;
	return (res);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

void	set_size_strs(char *str, char *sep, int *size, int *li_size)
{
	int	i;
	int	len;
	int	max;

	i = -1;
	len = 0;
	max = 0;
	while (str[len])
		len++;
	while (str[++i])
	{
		max++;
		if (is_sep(str[i], sep) == 1)
		{
			if (i != 0 && is_sep(str[i - 1], sep) && is_sep(str[i], sep))
				continue ;
			(*size)++;
			*li_size = *li_size < max ? max : *li_size;
			max = 0;
		}
	}
	if (is_sep(str[0], sep) && is_sep(str[len - 1], sep))
		(*size)--;
	else if (!is_sep(str[0], sep) && !is_sep(str[len - 1], sep))
		(*size)++;
}

char	**strs_cpy(char **strs, char *str, char *sep, int size)
{
	int	row;
	int	col;
	int	i;

	i = -1;
	row = 0;
	col = 0;
	while (str[++i])
	{
		if (is_sep(str[i], sep))
			continue ;
		if (!is_sep(str[i], sep))
		{
			strs[row][col] = str[i];
			col++;
		}
		if (!is_sep(str[i], sep) && is_sep(str[i + 1], sep))
		{
			strs[row][col] = 0;
			col = 0;
			row++;
		}
	}
	size != row ? strs[row][col] = 0 : 0;
	return (strs);
}

char	**ft_split(char *str, char *charset)
{
	int		size;
	int		li_size;
	char	**strs;
	int		i;

	i = -1;
	size = 0;
	li_size = 0;
	set_size_strs(str, charset, &size, &li_size);
	if ((strs = (char **)malloc(sizeof(char *) * (size + 1))) == NULL)
		return (0);
	while (++i < size)
		if ((strs[i] = (char *)malloc(sizeof(char) * li_size + 1)) == NULL)
			return (0);
	if (size == 0)
	{
		strs[0] = 0;
		return (strs);
	}
	strs = strs_cpy(strs, str, charset, size);
	strs[size] = 0;
	return (strs);
}
