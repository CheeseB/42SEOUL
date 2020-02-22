/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 01:34:49 by seongkim          #+#    #+#             */
/*   Updated: 2020/02/06 19:30:06 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	sub;

	i = 0;
	while (s1[i] || s2[i])
	{
		sub = s1[i] - s2[i];
		if (sub != 0)
			return (sub);
		i++;
	}
	return (0);
}

void	print_argv(int argc, char **argv)
{
	int	i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		idx;
	char	*temp;

	i = 1;
	while (i < argc)
	{
		idx = 1;
		while (idx < argc - 1)
		{
			if (ft_strcmp(argv[idx], argv[idx + 1]) > 0)
			{
				temp = argv[idx];
				argv[idx] = argv[idx + 1];
				argv[idx + 1] = temp;
			}
			idx++;
		}
		i++;
	}
	print_argv(argc, argv);
	return (0);
}
