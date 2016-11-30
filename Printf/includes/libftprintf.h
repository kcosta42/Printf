/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 15:13:49 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/29 20:50:11 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>
# include <wchar.h>

# define HEX	"0123456789abcdef"

# define L_HH	0
# define L_H	1
# define L_L	2
# define L_LL	3
# define L_J	4
# define L_Z	5

typedef	unsigned char	t_byte;

typedef struct	s_flags
{
	int			hash;
	int			zero;
	int			minus;
	int			plus;
	int			space;
}				t_flags;

typedef struct	s_format
{
	t_flags		flags;
	int			width;
	int			precision;
	int			length;
	char		type;
}				t_format;

int				ft_printf(const char *format, ...);
int				ft_printf_format(va_list ap, const char **str, int *size);
int				ft_printf_flush_format(const char **str, t_format *format,
																	int *size);
int				ft_printf_hex(uintmax_t nb, t_format *format);
void			ft_get_width(va_list ap, const char **str, t_format *format);

int				ft_printf_print_arg(va_list ap, t_format *format, int *size);
int				ft_printf_print_num(va_list ap, t_format *format);
int				ft_printf_print_unsigned(va_list ap, t_format *format);
int				ft_printf_print_octal(va_list ap, t_format *format);
int				ft_printf_print_hex(va_list ap, t_format *format);
int				ft_printf_print_address(va_list ap, t_format *format);
int				ft_printf_print_str(va_list ap, t_format *format);
int				ft_printf_print_char(va_list ap, t_format *format);
int				ft_printf_pourcent(t_format *format);

int				ft_toupper(int c);
int				ft_isspace(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);

int				ft_printf_isflag(int c);
int				ft_printf_islength(int c);
int				ft_printf_istype(int c);

char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_strdel(char **as);
int				ft_atoi(const char *str);

void			ft_putchar(char c);
void			ft_putwchar(wint_t c);
size_t			ft_putnstr(const char *str, size_t len);
size_t			ft_strlen(const char *str);
int				ft_wcharlen(wint_t c);

#endif
