/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:08:43 by paribeir          #+#    #+#             */
/*   Updated: 2024/03/07 17:56:30 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

/*** macros ***/
# define _GNU_SOURCE
# define WAIT 100

/*** libraries ***/
# include "./libft/libft.h"
# include <signal.h> //signal, sigemptyset, sigaddset, sigaction, kill
# include <unistd.h> //write,  getpid, pause, sleep, unsleep
# include <stdlib.h> //malloc, free, exit
# include <sys/types.h> //pid_t (data type for process IDs)

/*** client ***/
void	ft_dtob(int pid, char *c);
void	ft_client_signals(void);
void	ft_client_handler(int signum);

/*** server ***/
void	ft_server_handler(int signum, siginfo_t *info, void *context);

#endif