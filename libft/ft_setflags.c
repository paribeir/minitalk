/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:28:35 by paribeir          #+#    #+#             */
/*   Updated: 2023/12/12 11:30:20 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_boolflags(char c, t_flags *flag);

int	ft_setflags(char *str, t_flags *flag)
{
	char	*flags_array;
	size_t	i;

	i = 0;
	flags_array = "-+ 0#";
	while (ft_strchr(flags_array, str[i]))
		i += ft_boolflags(str[i], flag);
	while (ft_isdigit(str[i]))
	{
		flag->min_width = flag->min_width * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		flag->precision = 0;
		i++;
		while (ft_isdigit(str[i]))
		{
			flag->precision = flag->precision * 10 + (str[i] - '0');
			i++;
		}
	}
	return (i);
}

int	ft_boolflags(char c, t_flags *flag)
{
	if (c == '+')
	{
		flag->plus = 1;
		flag->space = 0;
	}
	else if (c == '-')
	{
		flag->minus = 1;
		flag->zero = 0;
	}
	else if (c == '0' && flag->minus == 0)
	{
		flag->zero = 1;
	}
	else if (c == ' ' && flag->plus == 0)
		flag->space = 1;
	else if (c == '#')
		flag->hashtag = 2;
	return (1);
}
