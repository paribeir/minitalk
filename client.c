/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:46:49 by paribeir          #+#    #+#             */
/*   Updated: 2024/03/04 17:15:17 by paribeir         ###   ########.fr       */
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
		if (ft_isdigit(argv[1][i++]))
			return (ft_printf("Error\n--> PID must only contain digits\n"));
	}
	if (ft_atoi(argv[1]) < 1)
		return (ft_printf("Error\n--> PID must be an unsigned int\n"));
	ft_printf("Client's PID: %d\n", getpid());
	ft_changesignals();
	while (argv[2][i])
		ft_encode(ft_atoi(argv[1]), argv[2][i++]);
	return (0);
}

/*convert char into byte with bitwise operationssss*/
void	ft_encode(int server_id, char c)
{
	int	byte;

	byte = 8;
	while (byte-- > 0)
	{
		
	}
}

void	ft_changesignals(void)
{
	struct sigaction	sa_action;

	sigemptyset(&sa_action.sa_mask);
	sa_action.sa_handler = client_handler;
	sa_action.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_action, NULL) == -1 || 
		sigaction(SIGUSR2, &sa_action, NULL) == -1)
		return (ft_printf("sigaction error\n"));
}

void	client_handler(int signum)
{
	if (signum == SIGUSR2)
		ft_printf("character received\n");
}
