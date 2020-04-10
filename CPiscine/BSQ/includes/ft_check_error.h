/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:46:09 by seongkim          #+#    #+#             */
/*   Updated: 2020/02/12 13:01:01 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECK_ERROR_H
# define FT_CHECK_ERROR_H

int	check_is_repeated(char *info, int info_leng);
int	check_is_printable(char info);
int	check_map_valid(char **map, int row_len, int col_len, char *info_box);
int	check_info_error(char *info, int *info_row_len, char *info_box);
int	check_map_error(char **map, int info_row_len, char *info_box);
int	check_error(char **map_file);

#endif
