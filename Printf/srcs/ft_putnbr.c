/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:54:08 by kcosta            #+#    #+#             */
/*   Updated: 2016/11/12 17:54:04 by kcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_putnbr(int n)
{
	long	nbr;
	int		digits;
	int		power;

	digits = ft_dcount(n);
	power = 1;
	while (--digits > 0)
		power *= 10;
	nbr = (long)n;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	while (power > 0)
	{
		ft_putchar(nbr / power + '0');
		nbr %= power;
		power /= 10;
	}
}
