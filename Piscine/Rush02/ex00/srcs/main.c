/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <seongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 10:09:16 by nakim             #+#    #+#             */
/*   Updated: 2020/02/12 17:07:18 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "search_print_dict.h"

void	print_str_main(char *str)
{
	int idx;

	idx = 0;
	while (str[idx])
	{
		write(1, &str[idx], 1);
		idx++;
	}
	write(1, "\n", 1);
}

void	print_error(t_argu_error error)
{
	if (error == ARGU_ERROR)
		print_str_main("Arguments is over than 3!");
	else if (error == KEY_ERROR)
		print_str_main("Input key argument is invalid!\n");
}

int		is_available_key(char *key)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (key[i++] != '\0')
		count++;
	i = 0;
	while (key[i] != '\0')
	{
		if (!(key[i] >= '0' && key[i] <= '9'))
			return (FALSE);
		if (key[0] == '0' && count != 1)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int		input_check(int argc, char **argv)
{
	if (argc > 3)
	{
		print_error(ARGU_ERROR);
		return (FALSE);
	}
	else if (argc == 2)
	{
		if (!(is_available_key(argv[1])))
		{
			print_error(KEY_ERROR);
			return (FALSE);
		}
	}
	else if (argc == 3)
	{
		if (!(is_available_key(argv[2])))
		{
			print_error(KEY_ERROR);
			return (FALSE);
		}
	}
	return (TRUE);
}

int		main(int argc, char *argv[])
{
	t_dict	dict;

	if (!(input_check(argc, argv)))
		return (0);
	if (argc == 2)
		dict = ft_load_default_dictionary();
	else
		dict = ft_load_dictionary(argv[1]);
	search_print_dict(dict.entries, argv[1]);
	return (0);
}
