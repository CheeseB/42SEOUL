/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:58:14 by seongkim          #+#    #+#             */
/*   Updated: 2020/02/06 04:52:29 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	base_error(char *base, int *size)
{
	int			i;
	int			j;
	const int	error = 1;
	const int	correct = 0;

	i = -1;
	while (base[++i])
		if (base[i] == '+' || base[i] == '-' ||
		(base[i] >= '\t' && base[i] <= '\r') || base[i] == ' ')
			return (error);
	*size = i;
	if (*size <= 1)
		return (error);
	i = -1;
	while (++i < *size - 1)
	{
		j = i + 1;
		while (j < *size)
			if (base[i] == base[j++])
				return (error);
	}
	return (correct);
}

int	str_check(char *str, int *sign)
{
	int	i;

	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

int	base_atoi(char *str, char *base, int size, int i)
{
	int	j;
	int	result;

	result = 0;
	while (str[i])
	{
		j = 0;
		while (base[j])
		{
			if (str[i] == base[j])
			{
				result = (result * size) + j;
				break ;
			}
			j++;
		}
		if (j == size)
			return (result);
		i++;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	str_to_int;
	int	sign;
	int	size;
	int	i;

	sign = 1;
	if (base_error(base, &size))
		return (0);
	i = str_check(str, &sign);
	str_to_int = base_atoi(str, base, size, i);
	return (str_to_int * sign);
}
