/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:53:36 by paribeir          #+#    #+#             */
/*   Updated: 2024/04/29 18:48:24 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

/*** macros ***/
# define _GNU_SOURCE
# define WAIT 300
/* ANSI colors */
# define BOLD	"\x1b[1m"
# define RED	"\x1b[31m"
# define GREEN	"\x1b[32m"
# define YELLOW	"\x1b[33m"
# define BLUE	"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN	"\x1b[36m"
# define RESET	"\x1b[0m"
# define SPACES	"        "

/*** libraries ***/
# include "./libft/libft.h"
# include <signal.h> //signal, sigemptyset, sigaddset, sigaction, kill
# include <unistd.h> //write,  getpid, pause, sleep, unsleep
# include <stdlib.h> //malloc, free, exit
# include <sys/types.h> //pid_t (data type for process IDs)
# include <sys/ioctl.h> //text colors

/*** client ***/
void	ft_client_dtob(int pid, char *c);
void	ft_client_config_sa(void);
void	ft_client_handler(int signum);

/*** server ***/
void	ft_server_message(void);
void	ft_server_config_sa(void);
void	ft_server_handler(int signum, siginfo_t *info, void *context);

#endif
