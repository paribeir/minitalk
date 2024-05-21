/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:22:08 by paribeir          #+#    #+#             */
/*   Updated: 2023/12/11 12:57:54 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_minus(char *n, t_flags *flag)
{
	int	i;

	i = 0;
	if (flag->precision != -1)
		i += ft_precision(n, flag);
	else
		i += ft_sign(flag);
	if (!(n[0] == '0' && flag->precision == 0))
		i += ft_putstr(n);
	while (i < flag->min_width)
		i += ft_putchar(' ');
	return (i);
}
