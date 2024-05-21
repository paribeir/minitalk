/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:46:49 by paribeir          #+#    #+#             */
/*   Updated: 2024/04/29 18:48:38 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//client is the speaker

#include "minitalk.h"

/*error handling*/
int	main(int argc, char *argv[])
{
	int		i;
	int		pid;
	char	*message;

	i = 0;
	if (argc != 3)
		return (ft_printf(RED BOLD "Error\n--> Client needs two arguments.\n"));
	if (!(*argv[2]))
		return (ft_printf(RED BOLD "Error\n--> Empty message\n"));
	while (argv[1][i])
	{
		if (!(ft_isdigit(argv[1][i++])))
		{
			ft_printf(RED BOLD "Error\n--> PID must only contain digits\n");
			return (1);
		}
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];
	if (pid < 1)
		return (ft_printf(RED BOLD "Error\n--> PID must be an unsigned int\n"));
	ft_client_config_sa();
	ft_client_dtob(pid, message);
	exit (EXIT_SUCCESS);
}

/*Converts char into binary with bitwise operations
and sends corresponding signals*/
void	ft_client_dtob(int server_id, char *c)
{
	int	i;
	int	k;

	while (*c)
	{
		i = 8;
		while (i-- > 0)
		{
			k = *c >> i;
			if (k & 1)
				kill((pid_t)server_id, SIGUSR1);
			else
				kill((pid_t)server_id, SIGUSR2);
			usleep(WAIT);
		}
		c++;
	}
	i = 8;
	while (i-- > 0)
	{
		kill((pid_t)server_id, SIGUSR2);
		usleep(WAIT);
	}
}

/*Defines behavior when Client receives a signal from Server*/
void	ft_client_config_sa(void)
{
	struct sigaction	sa_client;

	sigemptyset(&sa_client.sa_mask);
	sa_client.sa_handler = &ft_client_handler;
	sa_client.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_client, NULL) == -1 || 
		sigaction(SIGUSR2, &sa_client, NULL) == -1)
	{
		ft_printf("Sigaction error in Client\n");
		exit(EXIT_FAILURE);
	}
}

/*Function called when Client receives a signal.*/
void	ft_client_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf(GREEN BOLD "~~~ Message Received! ~~~\n" RESET);
		exit(EXIT_SUCCESS);
	}
}
