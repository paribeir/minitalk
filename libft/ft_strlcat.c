/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:54:25 by paribeir          #+#    #+#             */
/*   Updated: 2023/11/17 16:53:01 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb);

size_t	ft_strlcat(char *dest, const char *src, size_t dest_size)
{
	size_t	len_s;
	size_t	len_d;
	size_t	i;

	i = 0;
	len_s = ft_strlen(src);
	len_d = ft_strlen(dest);
	if (dest_size <= len_d)
		return (len_s + dest_size);
	else
		ft_strncat(dest, (char *)src, dest_size - len_d - 1);
	return (len_d + len_s);
}

char	*ft_strncat(char *dest, const char *src, size_t nbr)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < nbr)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}
