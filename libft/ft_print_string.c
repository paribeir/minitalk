/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:49:03 by paribeir          #+#    #+#             */
/*   Updated: 2024/02/01 17:38:45 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//width, minus, PRECISION

int	ft_minus_width(char *s, t_flags *flag);

int	ft_print_string(char *s, t_flags *flag)
{
	int		i;
	char	*str;

	i = 0;
	if (s == NULL)
	{
		if (flag->precision == -1 || flag->precision >= 6)
			s = "(null)";
		else
			flag->precision = -1;
	}
	if (flag->precision != -1)
	{
		str = (char *)malloc(flag->precision + 1);
		if (str == NULL)
			return (0);
		ft_strlcpy_int(str, (const char *)s, flag->precision + 1);
		i += ft_minus_width(str, flag);
		free (str);
	}
	else
		i += ft_minus_width(s, flag);
	return (i);
}

int	ft_minus_width(char *s, t_flags *flag)
{
	int		i;

	i = 0;
	if (flag->minus)
	{
		i += ft_putstr(s);
		while (i < flag->min_width)
			i += ft_putchar(' ');
		return (i);
	}
	else if (flag->min_width)
		i += ft_width(s, flag);
	i += ft_putstr(s);
	return (i);
}
