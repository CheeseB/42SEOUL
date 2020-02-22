/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:40:51 by seongkim          #+#    #+#             */
/*   Updated: 2020/02/03 17:51:06 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		s_idx;
	int		t_idx;
	int		temp_idx;
	int		flag;
	char	*ptr;

	if (!*str)
		return (str);
	s_idx = -1;
	while (str[++s_idx])
	{
		temp_idx = s_idx;
		t_idx = -1;
		flag = 1;
		while (to_find[++t_idx])
			if (str[temp_idx++] != to_find[t_idx])
			{
				flag = 0;
				break ;
			}
		if (flag)
			return (&str[s_idx]);
	}
	ptr = 0;
	return (ptr);
}
