/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinlee <jinlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 12:17:05 by jinlee            #+#    #+#             */
/*   Updated: 2020/02/09 23:23:02 by jinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_is_check.h"

t_bool	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

t_bool	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\v'
		|| c == '\f' || c == '\r')
		return (TRUE);
	return (FALSE);
}

t_bool	is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (TRUE);
	return (FALSE);
}
