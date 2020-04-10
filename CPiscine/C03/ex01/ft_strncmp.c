/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:38:59 by seongkim          #+#    #+#             */
/*   Updated: 2020/01/31 15:26:32 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	sub;

	sub = 0;
	while ((*s1 || *s2) && n--)
	{
		sub = *(unsigned char *)s1++ - *(unsigned char *)s2++;
		if (sub != 0)
			return (sub);
	}
	return (0);
}
