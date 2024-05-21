/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:42:17 by paribeir          #+#    #+#             */
/*   Updated: 2024/02/02 13:33:13 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//all numbers will be positive

static long	ft_nbr_digits(long n);

char	*ft_itoa_printf(long n)
{
	char	*str;
	int		len;

	len = (long)ft_nbr_digits(n);
	str = (char *)ft_calloc(len + 1, 1);
	if (str == NULL)
		return (NULL);
	if (n < 0)
		n *= -1;
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[--len] = (n % 10) + 48;
		n = n / 10;
	}
	return (str);
}

static long	ft_nbr_digits(long n)
{
	long	digits;

	digits = 0;
	if (n == 0)
		digits = 1;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}
