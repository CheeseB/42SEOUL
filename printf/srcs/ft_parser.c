/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 22:35:37 by seongkim          #+#    #+#             */
/*   Updated: 2020/09/22 22:40:50 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_parse_flag(const char *s, t_flag *flag)
{
	int		i;

	i = 0;
	if (s[0] == '0')
		flag->zero = 1;
	while (s[i] == '-' || s[i] == '0' || s[i] == ' ')
	{
		if (s[i] == '-')
			flag->minus = 1;
		if (s[i] == ' ')
			flag->int_space = 1;
		i++;
	}
	return (i);
}

int			ft_parse_width(const char *s, t_flag *flag, va_list ap)
{
	int		i;

	i = 0;
	if (s[i] == '*')
	{
		if ((flag->width = va_arg(ap, int)) < 0)
		{
			flag->minus = 1;
			flag->width *= -1;
		}
		i++;
	}
	else if (ft_isdigit(s[i]))
		while (ft_isdigit(s[i]))
		{
			flag->width = flag->width * 10 + s[i] - '0';
			i++;
		}
	while (s[i] == '*' || ft_isdigit(s[i]) || s[i] == ' ')
		i++;
	return (i);
}

int			ft_parse_precision(const char *s, t_flag *flag, va_list ap)
{
	int		i;

	i = 0;
	if (s[i] == '.')
	{
		i++;
		flag->dot = 0;
		if (s[i] == '*')
		{
			flag->dot = va_arg(ap, int);
		}
		else if (ft_isdigit(s[i]))
			while (ft_isdigit(s[i]))
			{
				flag->dot = (flag->dot) * 10 + s[i] - '0';
				i++;
			}
		while (s[i] == '.' || s[i] == '*' || ft_isdigit(s[i]) || s[i] == ' ')
			i++;
	}
	return (i);
}

int			ft_conversion(const char *s, int size, va_list ap)
{
	t_flag	flag;
	int		i;

	init_flag(&flag);
	i = ft_parse_flag(s, &flag);
	i += ft_parse_width(&s[i], &flag, ap);
	i += ft_parse_precision(&s[i], &flag, ap);
	if (i != size - 1)
		return (0);
	if (flag.zero == 1 && flag.minus == 1)
		flag.zero = 0;
	return (ft_handle(flag, s[i], ap));
}

int			handle_input(const char *str, va_list ap)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if ((j = is_conversion(&str[i])))
		{
			if (j == -1)
				return (0);
			count += ft_conversion(&str[i + 1], j, ap);
			i = i + j + 1;
		}
		else
			count += ft_putchar(str[i++]);
	}
	return (count);
}
