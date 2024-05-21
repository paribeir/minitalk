/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:04:10 by paribeir          #+#    #+#             */
/*   Updated: 2023/11/21 14:52:51 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	arr[13];
	long	num;
	int		i;

	num = n;
	i = 0;
	if (num < 0)
	{
		write(fd, "-", 1);
		num *= -1;
	}
	else if (num == 0)
		write(fd, "0", 1);
	while (num > 0)
	{
		arr[i++] = (num % 10) + 48;
		num = num / 10;
	}
	while (--i >= 0)
		write(fd, &arr[i], 1);
}
