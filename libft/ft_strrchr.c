/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:48:59 by paribeir          #+#    #+#             */
/*   Updated: 2023/11/17 19:20:28 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* len + 1 is important to make sure the loop iterates over the entire string,
starting from the the '\0'*/

char	*ft_strrchr(const char *str, int c)
{
	size_t	len;

	len = ft_strlen(str);
	if (c == '\0')
		return ((char *)&str[len]);
	while (len + 1 > 0)
	{
		if (str[len] == (unsigned char)c)
			return ((char *)&str[len]);
		len--;
	}
	return (NULL);
}
