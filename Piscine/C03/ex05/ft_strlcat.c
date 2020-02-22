/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:41:49 by seongkim          #+#    #+#             */
/*   Updated: 2020/02/03 18:13:49 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d_idx;
	unsigned int	d_count;
	unsigned int	s_idx;
	unsigned int	s_count;

	d_count = 0;
	s_count = 0;
	while (dest[d_count])
		d_count++;
	while (src[s_count])
		s_count++;
	d_idx = d_count;
	s_idx = 0;
	while (src[s_idx] && size > d_count + 1)
	{
		dest[d_idx] = src[s_idx];
		d_idx++;
		s_idx++;
		size--;
	}
	dest[d_idx] = '\0';
	if (d_count > size)
		return (s_count + size);
	else
		return (d_count + s_count);
}
