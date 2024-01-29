/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:46:53 by paribeir          #+#    #+#             */
/*   Updated: 2024/01/29 16:24:08 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
//server is the listener

//make a "bit to char" bzw "decrypt" function.

void	server(int client_pid, int client_message)
{
	int	server_pid;

	server_pid = getpid();
	printf("Server's PID: %d", server_pid);
	while(1)
	{
		sleep(1);
	}
}

