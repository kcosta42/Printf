/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_misc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 12:01:17 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/29 16:14:25 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include "libftprintf.h"

int		ft_toupper(int c)
{
	if (ft_isalpha(c) && c > 'Z')
		return (c - ('a' - 'A'));
	return (c);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}

size_t	ft_putnstr(const char *str, size_t len)
{
	size_t		ret;

	ret = len;
	if (!str)
		return (0);
	while (len-- && *str)
		ft_putchar(*str++);
	return (ret);
}

int		ft_printf_pourcent(t_format *format)
{
	size_t	size;

	size = 1;
	if (format->flags.minus)
	{
		ft_putchar('%');
		while ((size_t)format->width > size++)
			ft_putchar((format->flags.zero) ? '0' : ' ');
	}
	else
	{
		while ((size_t)format->width > size++)
			ft_putchar((format->flags.zero) ? '0' : ' ');
		ft_putchar('%');
	}
	return (size - 1);
}
