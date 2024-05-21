/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sign.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:23:00 by paribeir          #+#    #+#             */
/*   Updated: 2023/12/07 12:52:21 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sign(t_flags *flag)
{
	int	i;

	i = 0;
	if (!flag->negative)
	{
		if (flag->plus)
			i += ft_putchar('+');
		else if (flag->space)
			i += ft_putchar(' ');
	}
	else
		i += ft_putchar('-');
	return (i);
}
