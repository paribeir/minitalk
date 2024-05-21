/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:39:16 by paribeir          #+#    #+#             */
/*   Updated: 2023/12/07 14:47:32 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hex(unsigned long long nbr, char *base)
{
	int			temp_arr[20];
	char		*hexastr;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (nbr == 0)
		temp_arr[i++] = nbr;
	while (nbr > 0)
	{
		temp_arr[i++] = nbr % 16;
		nbr = nbr / 16;
	}
	hexastr = (char *)malloc(i + 1);
	if (hexastr == NULL)
		return (NULL);
	while (i > 0)
		hexastr[j++] = base[temp_arr[--i]];
	hexastr[j] = '\0';
	return (hexastr);
}
