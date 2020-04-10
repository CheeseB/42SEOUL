/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:40:20 by seongkim          #+#    #+#             */
/*   Updated: 2020/02/03 14:11:46 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	d_idx;
	int	s_idx;

	d_idx = 0;
	s_idx = 0;
	while (dest[d_idx])
	{
		d_idx++;
	}
	while (src[s_idx] && nb--)
	{
		dest[d_idx] = src[s_idx];
		d_idx++;
		s_idx++;
	}
	dest[d_idx] = '\0';
	return (dest);
}
