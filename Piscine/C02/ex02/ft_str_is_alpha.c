/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:55:30 by seongkim          #+#    #+#             */
/*   Updated: 2020/01/27 19:59:41 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] < 65 || str[idx] > 90)
		{
			if (str[idx] < 97 || str[idx] > 122)
			{
				return (0);
			}
		}
		idx++;
	}
	return (1);
}
