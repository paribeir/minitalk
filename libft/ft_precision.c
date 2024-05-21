/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:22:37 by paribeir          #+#    #+#             */
/*   Updated: 2023/12/11 11:50:03 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_precision(char *n, t_flags *flag)
{
	int	i;
	int	j;

	i = 0;
	j = flag->precision;
	if (flag->precision < ft_strlen_int(n) && n[0] != '0')
		j = ft_strlen_int(n);
	if (!flag->minus)
	{
		if (flag->plus || flag->negative)
			flag->min_width--;
		while (flag->min_width > j)
		{
			i += ft_putchar(' ');
			flag->min_width--;
		}
	}
	i += ft_sign(flag);
	while (flag->precision - ft_strlen_int(n) > 0)
	{
		i += ft_putchar('0');
		flag->precision--;
	}
	return (i);
}
