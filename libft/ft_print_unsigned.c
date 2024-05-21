/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:12:09 by paribeir          #+#    #+#             */
/*   Updated: 2024/02/02 13:14:14 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//width, minus, zero, precision

int	ft_print_unsigned(unsigned int n, t_flags *flag)
{
	int		i;
	char	*str_nbr;

	i = 0;
	str_nbr = ft_itoa_printf((long)n);
	if (flag->plus || flag->space)
		;
	if (flag->minus && flag->min_width)
		i += ft_minus(str_nbr, flag);
	else 
	{
		if (flag->precision != -1)
			i += ft_precision(str_nbr, flag);
		else if (flag->zero)
			i += ft_zero(str_nbr, flag);
		else if (flag->min_width)
			i += ft_width(str_nbr, flag);
		if (!(n == 0 && flag->precision == 0))
			i += ft_putstr(str_nbr);
	}
	free (str_nbr);
	return (i);
}
