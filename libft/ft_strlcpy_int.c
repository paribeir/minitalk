/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:27:58 by paribeir          #+#    #+#             */
/*   Updated: 2024/02/01 17:11:11 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*changed to return an int*/

int	ft_strlcpy_int(char *dest, const char *src, int dest_size)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen_int(src);
	if (dest_size == 0)
		return (j);
	while (i++ < (dest_size - 1) && *src)
		*(dest++) = *(src++);
	*dest = '\0';
	return (j);
}
