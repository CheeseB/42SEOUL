/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:22:44 by seongkim          #+#    #+#             */
/*   Updated: 2020/02/13 21:44:08 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

char				*ft_strcpy(char *dest, char *src)
{
	int	idx;

	idx = 0;
	while (src[idx] != '\0')
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str *t_stock;
	int			i;
	int			len;

	i = 0;
	t_stock = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!t_stock)
		return (0);
	while (i < ac)
	{
		len = ft_strlen(av[i]);
		t_stock[i].size = len;
		t_stock[i].str = (char *)malloc(len + 1);
		ft_strcpy(t_stock[i].str, av[i]);
		t_stock[i].copy = (char *)malloc(len + 1);
		ft_strcpy(t_stock[i].copy, av[i]);
		i++;
	}
	t_stock[i].str = 0;
	return (t_stock);
}
