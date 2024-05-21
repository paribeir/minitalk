/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:12:09 by paribeir          #+#    #+#             */
/*   Updated: 2023/11/20 16:54:17 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	int		start;
	int		end;
	int		new_size;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (!set || !s1)
		return (NULL);
	while (start <= end && ft_strchr(set, s1[start]))
		start++;
	if (start > end)
		return (ft_strdup(""));
	while (end >= 0 && ft_strchr(set, s1[end]))
		end--;
	new_size = end - start + 2;
	new_str = (char *)malloc(new_size);
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, &s1[start], new_size);
	return (new_str);
}
