/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexlow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:34:08 by paribeir          #+#    #+#             */
/*   Updated: 2023/12/11 15:17:53 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//width, minus, hashtag, zero, precision
int	ft_print_hexlow_cont(char *hexa, unsigned int n, t_flags *flag);

int	ft_print_hexlow(unsigned int n, t_flags *flag)
{
	int		i;
	char	*hexa;

	i = 0;
	hexa = ft_hex((unsigned long)n, HEX_LOW);
	if (flag->minus)
	{
		if (flag->hashtag && n != 0)
			i += ft_putstr(P);
		i += ft_minus(hexa, flag);
		free (hexa);
		return (i);
	}
	else 
		i += ft_print_hexlow_cont(hexa, n, flag);
	free (hexa);
	return (i);
}

int	ft_print_hexlow_cont(char *hexa, unsigned int n, t_flags *flag)
{
	int	i;

	i = 0;
	if (flag->hashtag && n != 0)
		i += ft_putstr(P);
	if (flag->precision != -1)
		i += ft_precision(hexa, flag);
	else if (flag->zero)
		i += ft_zero(hexa, flag);
	else if (flag->min_width)
	{
		i += ft_width(hexa, flag);
		if (flag->hashtag != 0 && n != 0)
			ft_putstr(P);
	}
	if (!(n == 0 && flag->precision == 0))
		i += ft_putstr(hexa);
	return (i);
}
