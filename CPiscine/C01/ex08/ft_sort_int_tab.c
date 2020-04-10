/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:02:50 by seongkim          #+#    #+#             */
/*   Updated: 2020/01/27 14:30:43 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *num1, int *num2)
{
	int	temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int idx;

	i = 0;
	while (i < size - 1)
	{
		idx = 0;
		while (idx < size - 1)
		{
			if (tab[idx] > tab[idx + 1])
			{
				swap(&tab[idx], &tab[idx + 1]);
			}
			idx++;
		}
		i++;
	}
}
