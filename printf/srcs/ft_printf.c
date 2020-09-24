/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 16:28:09 by seongkim          #+#    #+#             */
/*   Updated: 2020/09/22 22:39:10 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			is_conversion(const char *s)
{
	int		i;

	i = 1;
	if (s[0] == '%')
	{
		while (s[i] != 'c' && s[i] != 's' && s[i] != 'p' && s[i] != 'i'
				&& s[i] != 'd' && s[i] != 'u' && s[i] != 'x'
				&& s[i] != 'X' && s[i] != '%' && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			return (-1);
		return (i);
	}
	else
		return (0);
}

void		init_flag(t_flag *flag)
{
	flag->minus = 0;
	flag->zero = 0;
	flag->dot = -1;
	flag->width = 0;
	flag->int_space = 0;
	return ;
}

int			ft_handle(t_flag flag, char c, va_list ap)
{
	if (c == 'c')
		return (ft_handle_char(va_arg(ap, int), flag));
	else if (c == 's')
		return (ft_handle_string(va_arg(ap, char *), flag));
	else if (c == 'p')
		return (ft_handle_pointer(va_arg(ap, unsigned long long), flag));
	else if (c == 'd' || c == 'i')
		return (ft_handle_int(va_arg(ap, int), flag));
	else if (c == 'u')
		return (ft_handle_unint((unsigned int)va_arg(ap, unsigned int), flag));
	else if (c == 'x')
		return (ft_handle_hex(va_arg(ap, unsigned int), 0, flag));
	else if (c == 'X')
		return (ft_handle_hex(va_arg(ap, unsigned int), 1, flag));
	else if (c == '%')
		return (ft_handle_percent(flag));
	return (0);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*str;
	int		count;

	count = 0;
	if (!(str = ft_strdup(format)))
		return (0);
	va_start(ap, format);
	count += handle_input(str, ap);
	va_end(ap);
	free(str);
	return (count);
}
