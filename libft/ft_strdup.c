/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:11:11 by paribeir          #+#    #+#             */
/*   Updated: 2023/11/15 19:30:04 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;

	new = (char *)malloc(ft_strlen(s) + 1);
	if (new == 0)
		return (NULL);
	ft_strlcpy(new, s, (ft_strlen(s) + 1));
	return (new);
}
