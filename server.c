/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:46:53 by paribeir          #+#    #+#             */
/*   Updated: 2024/04/29 18:48:25 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"
//server is the listener

int	main(void)
{
	ft_server_message();
	while (1)
		ft_server_config_sa();
	return (0);
}

/*Intro message*/
void	ft_server_message(void)
{
	ft_printf(BOLD GREEN SPACES "`* __    __     __     __   __     ");
	ft_printf("__     ______   ______     __         __  __     `*\n" RESET);
	ft_printf(BOLD YELLOW SPACES "  /\\ \"-./  \\   /\\ \\   /\\ \"-.\\ \\");
	ft_printf("   /\\ \\   /\\__  _\\ /\\  __ \\   /\\ \\       /\\ \\/ /    \n" RESET);
	ft_printf(BOLD CYAN SPACES"  \\ \\ \\-./\\ \\  \\ \\ \\  \\ \\ \\-.  \\  \\ \\ \\");
	ft_printf("  \\/_/\\ \\/ \\ \\  __ \\  \\ \\ \\____  \\ \\  _\"-.  \n" RESET);
	ft_printf(BOLD RED SPACES"   \\ \\_\\ \\ \\_\\  \\ \\_\\  \\  \\_\\\"\\_\\  \\");
	ft_printf(" \\_\\    \\ \\_\\  \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_\\ \\_\\ \n" RESET);
	ft_printf(BOLD MAGENTA SPACES"    \\/_/  \\/_/   \\/_/   \\/_/ \\/_/   \\/_/");
	ft_printf("     \\/_/   \\/_/\\/_/   \\/_____/   \\/_/\\/_/ \n" RESET);
	ft_printf(BOLD MAGENTA SPACES"`*                                        ");
	ft_printf("                                           `*\n" RESET);
	ft_printf(BOLD CYAN SPACES SPACES SPACES "🔗 PID: %d", getpid());
	ft_printf(SPACES "-~-~-        ✨ by: paribeir\n\n" RESET);
}

/*Defines behavior when Server receives a signal from Client*/
void	ft_server_config_sa(void)
{
	struct sigaction	sa_server;

	sigemptyset(&sa_server.sa_mask);
	sa_server.sa_flags = SA_SIGINFO;
	sa_server.sa_sigaction = &ft_server_handler;
	if (sigaction(SIGUSR1, &sa_server, NULL) == -1 || 
		sigaction(SIGUSR2, &sa_server, NULL) == -1)
		exit(ft_printf("Sigaction error in Server\n"));
}

/*Function called when Server receives a signal.*/
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
		if (c)
			ft_printf("%c", c);
		else
		{
			ft_printf("\n");
			kill(client_pid, SIGUSR1);
		}
		c = 0;
		bits = 0;
	}
}
