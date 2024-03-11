/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:46:49 by paribeir          #+#    #+#             */
/*   Updated: 2024/03/07 20:08:59 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//client is the speaker

#include "minitalk.h"
/*input error checking*/
int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc != 3)
		return (ft_printf("Error\n--> Client needs three arguments.\n"));
	if (!(*argv[2]))
		return (ft_printf("Error\n--> Empty message\n"));
	while (argv[1][i])
	{
		if (!(ft_isdigit(argv[1][i++])))
			return (ft_printf("Error\n--> PID must only contain digits\n"));
	}
	if (ft_atoi(argv[1]) < 1)
		return (ft_printf("Error\n--> PID must be an unsigned int\n"));
	ft_printf("Client's process ID: %d\n", getpid());
	ft_client_signals();
	ft_dtob(ft_atoi(argv[1]), argv[2]);
	ft_dtob(ft_atoi(argv[1]), "\n");
	exit (EXIT_SUCCESS);
}

/*convert char into binary with bitwise operationssss*/
void	ft_dtob(int server_id, char *c)
{
	int	i;
	int	k;

	while(*c)
	{
		i = 8;
		while (i-- > 0)
		{
			k = *c >> i;
			if (k & 1)
				kill((pid_t)server_id, SIGUSR1);
			else
				kill((pid_t)server_id, SIGUSR2);
			usleep(100);
		}
		c++;
	}
}
/*void	ft_dtob(int server_id, char c)
{
	int	i;
	int	bitmask;
	int	k;

	i = 8;
	bitmask = 0b10000000;
	while (i-- > 0)
	{
		k = (int)c & bitmask;
		if (k & 1)
			kill(server_id, SIGUSR1);
		else
			kill(server_id, SIGUSR2);
		bitmask = bitmask >> 1;
	}
}*/

void	ft_client_signals(void)
{
	struct sigaction	sa_action;

	sigemptyset(&sa_action.sa_mask);
	sa_action.sa_handler = &ft_client_handler;
	sa_action.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_action, NULL) == -1 || 
		sigaction(SIGUSR2, &sa_action, NULL) == -1)
	{
		ft_printf("sigaction error\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_client_handler(int signum)
{
	static int chars;

	if (signum == SIGUSR2)
		ft_printf("%d characters received\n", ++chars);
	else
		return ;
}
