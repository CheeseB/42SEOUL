/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinlee <jinlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:50:14 by jinlee            #+#    #+#             */
/*   Updated: 2020/02/09 20:44:53 by jinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "ft_dict_sort.h"
# include "ft_is_check.h"
# include "ft_check_dictionary.h"
# include "ft_load_dictionary.h"
# include "ft_split.h"
# include "ft_dict_insert.h"
# include "ft_free_dictionary.h"

typedef enum
{
	ARGU_ERROR,
	KEY_ERROR
}	t_argu_error;

#endif
