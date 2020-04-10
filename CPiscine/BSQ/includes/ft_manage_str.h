/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_str.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:49:20 by seongkim          #+#    #+#             */
/*   Updated: 2020/02/12 23:52:19 by jiyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MANAGE_STR_H
# define FT_MANAGE_STR_H

# include <stdlib.h>

int		ft_strslen(char **strs);
int		ft_strlen(char *str);
char	*ft_strdup(char *src);
char	*ft_strdup_cat(char *dest, char *src);

#endif
