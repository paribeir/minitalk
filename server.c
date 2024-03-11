/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:38:59 by paribeir          #+#    #+#             */
/*   Updated: 2024/03/07 19:02:55 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

//server is the listener
#include "minitalk.h"
/*Function that will handle the signal.*/
void	ft_server_handler(int signum, siginfo_t *info, void *context)
{
	static char c;
	pid_t client_pid;
	static int	bits;

	(void)context;
	client_pid = info->si_pid;
	//ft_printf("Received signal %d from process %d.\n", signum, client_pid);
	//ft_printf("SIGUSR1: %d SIGUSR2: %d.\n", SIGUSR1, SIGUSR2);
	if (signum == SIGUSR1 || signum == SIGUSR2)
	{
		if (signum == SIGUSR1)
			c += 1 << (7 - bits);
		bits++;
	}
	//ft_printf("bits: %d\n", bits);
	if (bits == 8)
	{
		if (c == '\0')
		{
			ft_printf("\n");
			ft_printf("end of message\n");
			kill(client_pid, SIGUSR1);
			exit(0);
		}
		ft_printf("%c", c);
		c = 0;
		bits = 0;
		kill(client_pid, SIGUSR2);
	}
}

/*void	server_handler(int signum, siginfo_t *info, void *context)
{
	static char c;
	int client_pid;
	static int	bits;

	(void)context;
	client_pid = info->si_pid;
	ft_printf("Received signal %d from process %d.\n", signum, client_pid);
	ft_printf("SIGUSR1: %d SIGUSR2: %d.\n", SIGUSR1, SIGUSR2);
	if (signum == SIGUSR1 || signum == SIGUSR2)
	{
		c |= (signum == SIGUSR1);
		bits++;
	}
	ft_printf("bits: %d\n", bits);
	if (bits == 8)
	{
		if (c == '\0')
		{
			ft_printf("\n");
			kill(client_pid, SIGUSR1);
			return ;
		}
		ft_printf("%c", c);
		c = 0;
		bits = 0;
		kill(client_pid, SIGUSR2);
	}
	else
		c <<= 1;
}*/

int	main(void)
{
	struct sigaction	s_action;

	ft_printf("Servus at your service.\n The server's process ID is %d\n", getpid());
	ft_printf("Waiting for a message...\n");

	sigemptyset(&s_action.sa_mask);
	s_action.sa_flags = SA_SIGINFO;
	s_action.sa_sigaction = &ft_server_handler;
	if (sigaction(SIGUSR1, &s_action, NULL) == -1 || 
		sigaction(SIGUSR2, &s_action, NULL) == -1)
		exit (ft_printf("sigaction error\n"));
	while (1)
		pause();
	return (0);
}
