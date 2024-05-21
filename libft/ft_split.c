/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:48:44 by paribeir          #+#    #+#             */
/*   Updated: 2024/02/01 16:02:16 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrwords(const char *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	i;
	size_t	j;
	size_t	nbr_words;

	nbr_words = 0;
	i = 0;
	array = (char **)ft_calloc((ft_nbrwords(s, c) + 1), sizeof(char *));
	if (!array || !s)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[i + j] && s[i + j] != c)
				j++;
			array[nbr_words++] = ft_substr(s, i, j);
			i += j;
		}
		else
			i++;
	}
	array[nbr_words] = NULL;
	return (array);
}

static int	ft_nbrwords(const char *s, char c)
{
	size_t	i;
	size_t	nbr_words;

	nbr_words = 0;
	i = 0;
	if (!*s)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			nbr_words++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (nbr_words);
}
