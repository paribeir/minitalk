/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:46:49 by paribeir          #+#    #+#             */
/*   Updated: 2024/01/29 16:24:10 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//client is the speaker

#include "minitalk.h"
int client(int pid, char *message);

int main(int argc, char *argv[]) 
{

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

	bit = /*turn it into string of bits.
	We want to have a sequence of 8-bit strings*/
}
