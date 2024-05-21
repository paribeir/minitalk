/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:21:07 by paribeir          #+#    #+#             */
/*   Updated: 2023/11/11 16:21:07 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buffer, int value, size_t num)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)buffer;
	while (num-- > 0)
		*(ptr++) = (unsigned char)value;
	return (buffer);
}
