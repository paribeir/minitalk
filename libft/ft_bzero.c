/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:41:07 by paribeir          #+#    #+#             */
/*   Updated: 2023/11/11 21:41:07 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *buffer, size_t num)
{
	ft_memset(buffer, 0, num);
}

/*void ft_bzero(void *buffer, size_t num)
{
    unsigned char    *ptr;

    ptr = (unsigned char *)buffer;
    while (num --> 0)
        *(ptr++) = 0;
}*/