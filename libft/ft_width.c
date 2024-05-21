/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:26:59 by paribeir          #+#    #+#             */
/*   Updated: 2023/12/09 12:55:59 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_width(char *n, t_flags *flag)
{
	int	i;

	i = 0;
	if (flag->plus || flag->negative || flag->space)
		i++;
	while (i < flag->min_width - ft_strlen_int(n))
		i += ft_putchar(' ');
	ft_sign(flag);
	return (i);
}
