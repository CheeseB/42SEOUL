/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:39:49 by seongkim          #+#    #+#             */
/*   Updated: 2020/01/31 16:17:39 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	d_idx;
	int	s_idx;

	d_idx = 0;
	s_idx = 0;
	while (dest[d_idx])
	{
		d_idx++;
	}
	while (src[s_idx])
	{
		dest[d_idx] = src[s_idx];
		d_idx++;
		s_idx++;
	}
	dest[d_idx] = '\0';
	return (dest);
}
