/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 20:38:53 by seongkim          #+#    #+#             */
/*   Updated: 2020/09/22 22:03:56 by seongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define HEX_BASE "0123456789abcdef"

typedef	struct	s_flag
{
	int		minus;
	int		zero;
	int		dot;
	int		width;
	int		int_space;
}				t_flag;

int				ft_handle_char(char c, t_flag flag);
int				ft_handle_hex(unsigned int n, int is_large, t_flag flag);
int				ft_handle_int(int n, t_flag flag);
int				ft_handle_percent(t_flag flag);
int				ft_handle_pointer(unsigned long long p, t_flag flag);
int				ft_handle_string(char *s, t_flag flag);
int				ft_handle_unint(unsigned int n, t_flag flag);
int				ft_handle_width(int width, int flag);

int				ft_printf(const char *format, ...);
int				handle_input(const char *str, va_list ap);
int				ft_conversion(const char *s, int size, va_list ap);
int				ft_parse_precision(const char *s, t_flag *flag, va_list ap);
int				ft_parse_width(const char *s, t_flag *flag, va_list ap);
int				ft_parse_flag(const char *s, t_flag *flag);
int				ft_handle(t_flag flag, char c, va_list ap);
void			init_flag(t_flag *flag);
int				is_conversion(const char *s);

char			*ft_str_toupper(char *str);
char			*ft_hex_itoa(unsigned long long n);
char			*ft_u_itoa(unsigned int n);
char			*ft_itoa(int n);
int				ft_strlen(const char *str);
char			*ft_strdup(const char *str);
int				ft_isdigit(char c);
int				ft_putchar(char c);
int				ft_putnstr(char *str, int size);

#endif
