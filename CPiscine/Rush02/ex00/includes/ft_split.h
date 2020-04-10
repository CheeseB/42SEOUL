/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinlee <jinlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:58:51 by jinlee            #+#    #+#             */
/*   Updated: 2020/02/09 20:08:52 by jinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPLIT_H
# define FT_SPLIT_H

# include <stdlib.h>

int		is_seperator(char c, char *sep);
int		chk_word_cnt(char *str, char *sep);
int		chk_word_len(char *str, char *sep, int idx);
void	insert_word(char *str, char *sep, char *result, int idx);
char	**ft_split(char *str, char *charset);

#endif
