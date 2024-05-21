/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:18:44 by paribeir          #+#    #+#             */
/*   Updated: 2024/02/02 14:17:17 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

//get next line
char	*get_next_line(int fd);
void	dangling_pointers(char **ptr);
char	*read_into_buffer(int fd, char *str_remainder, char *buffer);
char	*extract_remainder(char *read_str);

//utils
int		ft_strlen_gnl(const char *str);
char	*ft_strchr_gnl(const char *str, int c);
char	*ft_substr_gnl(char const *str, unsigned int start, size_t len);
char	*ft_strdup_gnl(char *src);
char	*ft_strjoin_gnl(char const *s1, char const *s2);

#endif
