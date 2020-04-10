/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:19:32 by jiyang            #+#    #+#             */
/*   Updated: 2020/02/10 20:54:37 by jiyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPLIT_H
# define FT_SPLIT_H

# include <stdlib.h>

char	**strs_cpy(char **strs, char *str, char *sep, int size);
char	**ft_split(char *str, char *charset);
void	set_size_strs(char *str, char *sep, int *size, int *li_size);
char	*ft_strcpy(char *dest, char *src);
int		is_sep(char ch, char *sep);

#endif
