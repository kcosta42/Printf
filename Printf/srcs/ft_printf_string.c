/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:29:00 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/24 19:24:04 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

static char		*ft_strnew(size_t size)
{
	char	*str;
	char	*ptrstr;

	if (!(str = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ptrstr = str;
	while (size + 1)
	{
		*ptrstr = 0;
		ptrstr++;
		size--;
	}
	return (str);
}

void			ft_strdel(char **as)
{
	if (!as)
		return ;
	free(*as);
	*as = NULL;
}

static char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*ptrdst;

	ptrdst = dst;
	while (*src && len)
	{
		*(ptrdst++) = *(src++);
		len--;
	}
	while (len)
	{
		*(ptrdst++) = 0;
		len--;
	}
	return (dst);
}

int				ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n && *s1 && *s2 && *(t_byte*)s1 == *(t_byte*)s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n)
		return (*(t_byte*)s1 - *(t_byte*)s2);
	return (0);
}

char			*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if (!(sub = ft_strnew(len)))
		return (NULL);
	while (start--)
		s++;
	return (ft_strncpy(sub, s, len));
}
