/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:33:13 by paribeir          #+#    #+#             */
/*   Updated: 2023/12/11 15:03:14 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_if(t_flags *flag)
{
	flag->plus = 0;
	flag->space = 0;
	flag->hashtag = 0;
	flag->minus = 0;
	flag->zero = 0;
	flag->precision = -1;
	flag->min_width = 0;
	flag->negative = 0;
	flag->percent = 0;
	return (1);
}
