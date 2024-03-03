/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:38:59 by paribeir          #+#    #+#             */
/*   Updated: 2024/03/03 20:38:17 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

/*Function that will handle the signal.*/

void handler (int signal_nbr, siginfo_t *info, void *ucontent)
{

}

int main(void)
{
    struct sigaction	s_action;

    s_action.sa_sigaction = handler;
    sigemptyset(&s_action.sa_mask);
    s_action.sa_flags = SA_SIGINFO;
    if (sigaction(SIGUSR1, &s_action, NULL) == -1 || sigaction(SIGUSR2, &s_action, NULL) == -1)
        return(ft_printf("sigaction error\n"));
    ft_printf("Servus at your service.\n The process ID is %d\n", getpid());
    return (0);
}
