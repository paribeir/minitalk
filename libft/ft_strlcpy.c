/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:27:58 by paribeir          #+#    #+#             */
/*   Updated: 2023/11/17 19:43:25 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*If dest_size is zero, return the source string*/
/*Else if dest_size is one, only write '\0' in destination string*/
/*Else, copy src into destination until dest_size - 1,
  since we need the last space to null-terminate the dest string*/

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(src);
	if (dest_size == 0)
		return (j);
	while (i++ < (dest_size - 1) && *src)
		*(dest++) = *(src++);
	*dest = '\0';
	return (j);
}
