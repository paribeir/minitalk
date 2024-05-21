/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:18:34 by paribeir          #+#    #+#             */
/*   Updated: 2024/02/02 14:17:47 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_gnl(const char *str, int c)
{
	while (*str)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}

int	ft_strlen_gnl(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr_gnl(char const *str, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if ((int)start > ft_strlen_gnl(str))
		return (ft_strdup_gnl(""));
	if (ft_strlen_gnl(str) - start < len)
		len = ft_strlen_gnl(str) - start;
	new = (char *)malloc(len + 1);
	if (new == NULL)
		return (NULL);
	while (i < len && str[start])
		new[i++] = str[start++];
	new[i] = '\0';
	return (new);
}

char	*ft_strdup_gnl(char *src)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	if (!src)
		return (NULL);
	while (src[len])
		len++;
	str = (char *)malloc(sizeof(*src) * (len + 1));
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
