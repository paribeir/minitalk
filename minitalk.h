/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:53:36 by paribeir          #+#    #+#             */
/*   Updated: 2024/03/04 17:07:47 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

/*** macros ***/
# define _GNU_SOURCE
# define WAIT 100

/*** libraries ***/
# include <signal.h> //signal, sigemptyset, sigaddset, sigaction, kill
# include <unistd.h> //write,  getpid, pause, sleep, unsleep
# include <stdlib.h> //malloc, free, exit
# include <sys/types.h> //pid_t (data type for process IDs)
# include "../libft/libft.h"

/*** client ***/
void	ft_encode(int pid, char c);
void	ft_changesignals(void);
void	client_handler(int signum);

/*** server ***/

#endif
