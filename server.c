/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:46:53 by paribeir          #+#    #+#             */
/*   Updated: 2024/03/04 17:00:10 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//server is the listener
#include "minitalk.h"
/*Function that will handle the signal.*/
void	server_handler(int signum, siginfo_t *info, void *content)
{
	ft_printf("Received signal %d from process %d.\n", signum, info->si_pid);
	if (signum == SIGUSR1)
		ft_printf("0\n");
	else if (signum == SIGUSR2)
		ft_printf("1\n");
}

int	main(void)
{
	struct sigaction	s_action;

	sigemptyset(&s_action.sa_mask);
	s_action.sa_flags = SA_SIGINFO;
	s_action.sa_sigaction = server_handler;
	if (sigaction(SIGUSR1, &s_action, NULL) == -1 || 
		sigaction(SIGUSR2, &s_action, NULL) == -1)
		return (ft_printf("sigaction error\n"));
	ft_printf("Servus at your service.\n The process ID is %d\n", getpid());
	while (1)
		pause();
	return (0);
}
