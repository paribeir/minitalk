/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:40:35 by paribeir          #+#    #+#             */
/*   Updated: 2023/12/12 11:29:15 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		printed;
	int		mapped;
	t_flags	flag;

	i = 0;
	printed = 0;
	mapped = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (ft_if(&flag) && (ft_strchr(FL, str[i]) || ft_isdigit(str[i])))
				i += ft_setflags((char *)&str[i], &flag);
			if (ft_strchr("cspdiuxX%", str[i]))
				mapped += ft_mapping(str[i++], &flag, args);
		}
		else
			printed += ft_putchar(str[i++]);
	}
	va_end(args);
	return (printed += mapped);
}
