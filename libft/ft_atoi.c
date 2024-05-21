/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:12:48 by paribeir          #+#    #+#             */
/*   Updated: 2023/11/17 19:26:45 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*THE most beautiful atoi*/

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sum;
	int	minus;

	sum = 0;
	minus = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		sum = sum * 10 + (*str - 48);
		str++;
	}
	return (sum * minus);
}
