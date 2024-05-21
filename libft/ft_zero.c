/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:23:43 by paribeir          #+#    #+#             */
/*   Updated: 2024/02/01 17:09:17 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_zero(char *n, t_flags *flag)
{
	int	i;

	i = 0;
	i += ft_sign(flag);
	i += flag->hashtag;
	while (i < flag->min_width - ft_strlen_int(n))
		i += ft_putchar('0');
	return (i);
}
