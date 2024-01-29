/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:53:36 by paribeir          #+#    #+#             */
/*   Updated: 2024/01/29 15:33:06 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H 
# define MINITALK_H

# include <signal.h> //signal, sigemptyset, sigaddset, sigaction, kill
# include <unistd.h> //write,  getpid, pause, sleep, unsleep
# include <stdlib.h> //malloc, free, exit


//server
void	handle_sigusr1(int signum);
extern struct	sigaction sa;



#endif
