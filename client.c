/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:46:49 by paribeir          #+#    #+#             */
/*   Updated: 2024/04/26 18:58:31 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//client is the speaker

#include "minitalk.h"

/*input error checking*/
int	main(int argc, char *argv[])
{
	int		i;
	int		pid;
	char	*message;

	i = 0;
	if (argc != 3)
		return (ft_printf("Error\n--> Client needs two arguments.\n"));
	if (!(*argv[2]))
		return (ft_printf("Error\n--> Empty message\n"));
	while (argv[1][i])
	{
		if (!(ft_isdigit(argv[1][i++])))
			return (ft_printf("Error\n--> PID must only contain digits\n"));
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];
	if (pid < 1)
		return (ft_printf("Error\n--> PID must be an unsigned int\n"));
	ft_printf("Client's process ID: %d\n", getpid());
	ft_client_signals();
	ft_dtob(pid, message);
	ft_dtob(pid, "\n");
	exit (EXIT_SUCCESS);
}

/*convert char into binary with bitwise operationssss*/
void	ft_dtob(int server_id, char *c)
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

/*Defines what  we do when we receive a signal from the Server*/
void	ft_client_signals(void)
{
	struct sigaction	sa_client;

	sigemptyset(&sa_client.sa_mask);
	sa_client.sa_handler = &ft_client_handler;
	sa_client.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_client, NULL) == -1 || 
		sigaction(SIGUSR2, &sa_client, NULL) == -1)
	{
		ft_printf("Sigaction error in client\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_client_handler(int signum)
{
	static int	chars;

	if (signum == SIGUSR2)
		ft_printf("%d characters sent\n", ++chars);
	if (signum == SIGUSR1)
	{
		ft_printf("-------End of message!-------\n", ++chars);
		exit(EXIT_SUCCESS);
	}
}
