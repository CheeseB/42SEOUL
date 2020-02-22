/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_check.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinlee <jinlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 12:17:36 by jinlee            #+#    #+#             */
/*   Updated: 2020/02/09 19:07:41 by jinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IS_CHECK_H
# define FT_IS_CHECK_H

typedef enum
{
	FALSE,
	TRUE
}	t_bool;

t_bool	is_number(char c);
t_bool	is_printable(char c);
t_bool	is_space(char c);

#endif
