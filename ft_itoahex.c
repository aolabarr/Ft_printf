/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoahex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:25:23 by aolabarr          #+#    #+#             */
/*   Updated: 2024/01/27 13:53:54 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(size_t num);

char	*ft_itoahex(size_t num)
{
	char		*str;
	long int	len;

	len = ft_numlen(num);
	str = malloc((sizeof(char) * (len + 1)));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		if ((num % 16) <= 9)
			str[len] = (num % 16) + '0';
		else
			str[len] = (num % 16) + 'a' - 10;
		num = num / 16;
		len--;
	}
	return (str);
}

static int	ft_numlen(size_t num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		len = 1;
	while (num > 0)
	{
		num = num / 16;
		len++;
	}
	return (len);
}
