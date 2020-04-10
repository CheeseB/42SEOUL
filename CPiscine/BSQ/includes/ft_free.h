/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 21:30:37 by seongkim          #+#    #+#             */
/*   Updated: 2020/02/12 15:57:35 by jiyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FREE_H
# define FT_FREE_H

# include "ft_print.h"
# include <stdlib.h>

void	ft_strs_free(char **strs);
void	ft_ints_free(int **ints, int row);
void	ft_whole_free(char **strs, int **ints, int row);
void	ft_free_and_error(char **strs, int argc, int idx);

#endif
