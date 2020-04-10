/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_print_dict.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:51:23 by seongkim          #+#    #+#             */
/*   Updated: 2020/02/09 21:51:36 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef SEARCH_PRINT_DICT_H
#	define SEARCH_PRINT_DICT_H

#	include "ft_check_dictionary.h"

extern int	str_length(char *str);
extern char	**malloc_input(void);
extern void	input_argv(char **nums, char *argv, int mod);
extern void	print_nums(t_dict_entry dict[], char **nums, int div, int mod);
extern void	print_hundreds(t_dict_entry dict[], char *nums_row);
extern void	print_value(t_dict_entry dict[], char c[], int idx);
extern char	*search_dict_digit(t_dict_entry dict[], int digit);
extern char	*search_dict_key(t_dict_entry dict[], char *key);
extern int	my_strcmp(char *str1, char *str2);
extern void	free_nums(char **nums);
extern void	print_str(char *str);
extern void	search_print_dict(t_dict_entry dict[], char *argv);

#	endif
