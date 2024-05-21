/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:26:55 by paribeir          #+#    #+#             */
/*   Updated: 2023/12/12 11:29:29 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_mapping(char c, t_flags *flag, va_list args)
{
	if (c == 'c')
		return (ft_print_char(va_arg(args, int), flag));
	else if (c == 's')
		return (ft_print_string(va_arg(args, char *), flag));
	else if (c == 'p')
		return (ft_print_pointer(va_arg(args, void *), flag));
	else if (c == 'd' || c == 'i')
		return (ft_print_int(va_arg(args, int), flag));
	else if (c == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int), flag));
	else if (c == 'x')
		return (ft_print_hexlow(va_arg(args, unsigned int), flag));
	else if (c == 'X')
		return (ft_print_hexup(va_arg(args, unsigned int), flag));
	else if (c == '%')
	{
		ft_if(flag);
		return (ft_print_char('%', flag));
	}
	return (0);
}
