/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:46:53 by paribeir          #+#    #+#             */
/*   Updated: 2024/04/26 19:02:06 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

//server is the listener
/*Function that will handle the signal.*/

int	main(void)
{
	struct sigaction	sa_server;

	ft_printf("Servus at your service.\n My PID is: %d\n", getpid());
	ft_printf("Waiting for a message...\n");
	sigemptyset(&sa_server.sa_mask);
	sa_server.sa_flags = SA_SIGINFO;
	sa_server.sa_sigaction = &ft_server_handler;
	if (sigaction(SIGUSR1, &sa_server, NULL) == -1 || 
		sigaction(SIGUSR2, &sa_server, NULL) == -1)
		exit (ft_printf("Sigaction error in server\n"));
	while (1)
		pause();
	return (0);
}

void	ft_server_handler(int signum, siginfo_t *info, void *context)
{
	static char	c;
	pid_t		client_pid;
	static int	bits;

	(void)context;
	client_pid = info->si_pid;
	if (signum == SIGUSR1)
		c += 1 << (7 - bits);
	bits++;
	if (bits == 8)
	{
		if (!c)
		{
			ft_printf("\n");
			kill(client_pid, SIGUSR1);
		}
		else
		{
			ft_printf("%c", c);
			kill(client_pid, SIGUSR2);
		}
		c = 0;
		bits = 0;
	}
}
