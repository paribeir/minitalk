/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:17:16 by paribeir          #+#    #+#             */
/*   Updated: 2024/02/01 17:39:17 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//width, minus, plus, zero, precision, space

int	ft_printf_int_cont(char	*str_nbr, int n, t_flags *flag);

int	ft_print_int(int n, t_flags *flag)
{
	int		i;
	char	*str_nbr;

	i = 0;
	if (n < 0)
		flag->negative = 1;
	str_nbr = ft_itoa_printf((long)n);
	if (flag->minus && flag->min_width)
	{
		i += ft_minus(str_nbr, flag);
		free (str_nbr);
		return (i);
	}
	else 
		i += ft_printf_int_cont(str_nbr, n, flag);
	free (str_nbr);
	return (i);
}

int	ft_printf_int_cont(char	*str_nbr, int n, t_flags *flag)
{
	int	i;

	i = 0;
	if (flag->precision != -1)
		i += ft_precision(str_nbr, flag);
	else if (flag->zero)
		i += ft_zero(str_nbr, flag);
	else if (flag->min_width)
		i += ft_width(str_nbr, flag);
	else if (flag->negative || flag->plus || flag->space)
		i += ft_sign(flag);
	if (!(n == 0 && flag->precision == 0))
		i += ft_putstr(str_nbr);
	return (i);
}
