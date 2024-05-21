/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:14:03 by paribeir          #+#    #+#             */
/*   Updated: 2023/12/07 17:58:06 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//width, minus

int	ft_print_char(int n, t_flags *flag)
{
	char	c;
	int		i;

	i = 0;
	c = n;
	if (flag->minus && flag->min_width)
	{
		i += ft_putchar(c);
		while (i < flag->min_width)
			i += ft_putchar(' ');
		return (i);
	}
	else if (flag->min_width)
	{
		while (i < flag->min_width - 1)
			i += ft_putchar(' ');
	}
	return (i + ft_putchar(c));
}
