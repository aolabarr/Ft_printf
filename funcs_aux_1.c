/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_aux_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:51:39 by aolabarr          #+#    #+#             */
/*   Updated: 2024/01/27 14:22:38 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	char	c;
	int		count;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		count++;
	}
	if (n > 9)
		count += ft_putnbr(n / 10);
	c = n % 10 + '0';
	manage_char(c);
	count++;
	return (count);
}

int	ft_putnbru(unsigned int u)
{
	char	c;
	int		count;

	count = 0;
	if (u > 9)
		count += ft_putnbru(u / 10);
	c = u % 10 + '0';
	manage_char(c);
	count++;
	return (count);
}
