/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:43:12 by paribeir          #+#    #+#             */
/*   Updated: 2024/02/01 17:25:49 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*returns the number of written characters,
which is 1 on success and 0 on error (instead of -1).*/
int	ft_putchar(char c)
{
	if (write(1, &c, 1) != -1)
		return (1);
	return (0);
}
