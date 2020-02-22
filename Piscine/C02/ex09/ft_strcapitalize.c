/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:17:32 by seongkim          #+#    #+#             */
/*   Updated: 2020/01/28 19:36:44 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_upper(char *str, int idx)
{
	if (str[idx] < 48 || str[idx] > 57)
		if (str[idx] < 65 || str[idx] > 90)
			if (str[idx] < 97 || str[idx] > 122)
			{
				return (1);
			}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	idx;
	int	is_upper;

	idx = 0;
	is_upper = 1;
	while (str[idx] != '\0')
	{
		if (is_upper)
		{
			if (str[idx] >= 'a' && str[idx] <= 'z')
			{
				str[idx] -= 32;
			}
		}
		else
		{
			if (str[idx] >= 'A' && str[idx] <= 'Z')
			{
				str[idx] += 32;
			}
		}
		is_upper = check_upper(str, idx);
		idx++;
	}
	return (str);
}
