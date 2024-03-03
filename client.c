/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:46:49 by paribeir          #+#    #+#             */
/*   Updated: 2024/03/03 16:47:56 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//client is the speaker

#include "minitalk.h"

int main(int argc, char *argv[]) 
{

	if (argc != 3)
		return (ft_printf("Error\n--> The client needs two parameters.\n"));
	client(argc, argv[1]);
	//create stop condition.

}

int client(int server_pid, char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		
	}
	return (1);
}

int	char_to_bit(char c) //or maybe call it "encrypt"
{
	int	bit;

	bit = 1;/*turn it into string of bits.
	We want to have a sequence of 8-bit strings*/
}
