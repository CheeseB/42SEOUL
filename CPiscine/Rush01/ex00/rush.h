/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeocho <yeocho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 17:27:13 by seongkim          #+#    #+#             */
/*   Updated: 2020/02/02 23:33:53 by yeocho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef RUSH_H
#	define RUSH_H

#include <unistd.h>
#include <stdlib.h>

int		**set_real(void);
int		**set_see(char *argv);
void	input_4updown(int **realblock, int i, int j);
void	input_4leftright(int **realblock, int i, int j);
void	input_1(int **realblock, int i, int j);
void	input_23(int **seeblock, int **realblock, int i, int j);
void	input_12(int **seeblock, int **realblock, int i, int j);
void	print_block(int **realblock);
int		check_arr_col(int **seeblock);
int		check_arr_row(int **seeblock);
void	dfs(int depth, int row, int col, int **realblock);

#	endif
