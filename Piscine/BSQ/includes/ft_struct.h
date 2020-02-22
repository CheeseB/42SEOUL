/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 21:00:47 by seongkim          #+#    #+#             */
/*   Updated: 2020/02/11 14:52:39 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H

# include <stdlib.h>

typedef struct	s_map
{
	int		row;
	int		col;
	char	empty;
	char	obst;
	char	fill;
	char	**map;
	int		**num_map;
}				t_map;

t_map			ft_value_insert(t_map res, char **info);
int				**num_value_insert(char **info, char obst, char empty);

#endif
