/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:36:15 by paribeir          #+#    #+#             */
/*   Updated: 2023/12/11 14:46:09 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_ptr_null(void *ptr, char *n);

int	ft_print_pointer(void *ptr, t_flags *flag)
{
	int		i;
	char	*hexa;
	char	*n;

	i = 0;
	if (ptr == NULL)
		hexa = "(nil)";
	else
	{
		n = ft_hex((unsigned long)ptr, HEX_LOW);
		hexa = ft_strjoin(P, n);
		free (n);
	}
	if (flag->minus && flag->min_width)
	{
		i += ft_minus(hexa, flag);
		ft_check_ptr_null(ptr, hexa);
		return (i);
	}
	else if (flag->min_width)
		i += ft_width(hexa, flag);
	i += ft_putstr(hexa);
	ft_check_ptr_null(ptr, hexa);
	return (i);
}

void	ft_check_ptr_null(void *ptr, char *hexa)
{
	if (ptr != NULL)
		free (hexa);
}

/*	else if (flag->min_width)
		{
			while (i < flag->min_width - \
			ft_strlen_int(hexa) - flag->hashtag)
				i += ft_putchar(' ');
		}*/

/*i += ft_putstr(hexa);
		while (i < flag->min_width)
			i += ft_putchar(' ');*/
