/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:43:32 by paribeir          #+#    #+#             */
/*   Updated: 2023/11/21 14:57:00 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if (start > ft_strlen(str))
		return (ft_strdup(""));
	if (ft_strlen(str) - start < len)
		len = ft_strlen(str) - start;
	new = (char *)ft_calloc(len + 1, 1);
	if (new == NULL)
		return (NULL);
	while (i < len && str[start])
		new[i++] = str[start++];
	return (new);
}
