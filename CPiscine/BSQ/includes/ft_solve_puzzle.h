/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_puzzle.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 20:12:00 by seongkim          #+#    #+#             */
/*   Updated: 2020/02/12 14:26:18 by jiyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SOLVE_PUZZLE_H
# define FT_SOLVE_PUZZLE_H

# include "ft_macro.h"
# include "ft_print.h"
# include "ft_struct.h"

int		**ft_solve(t_map problem);
void	ft_solve_puzzle(t_map problem, int argc, int idx);
int		ft_find_min(int num1, int num2, int num3);
int		ft_find_max(t_map problem);
void	ft_put_square(t_map problem, int row, int col, int max);
void	ft_find_min_location(t_map problem, int max);

#endif
