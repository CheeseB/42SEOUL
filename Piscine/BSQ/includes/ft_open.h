/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:58:38 by jiyang            #+#    #+#             */
/*   Updated: 2020/02/11 15:11:48 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPEN_H
# define FT_OPEN_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	**file_open_read(char *file);

#endif
