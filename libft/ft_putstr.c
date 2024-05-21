/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:00:30 by paribeir          #+#    #+#             */
/*   Updated: 2024/02/02 13:14:09 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*returns the number of written characters,
which is strlen(s) on success and 0 on error (instead of -1).*/

int	ft_putstr(char *s)
{
	if (write(1, s, ft_strlen_int(s)) != -1)
		return (ft_strlen_int(s));
	return (0);
}
