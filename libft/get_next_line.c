/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:18:16 by paribeir          #+#    #+#             */
/*   Updated: 2024/02/02 14:19:23 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char		*read_str;
	char		*buffer;
	static char	*remainder[__FD_SETSIZE];

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
	{
		dangling_pointers(&buffer);
		dangling_pointers(&remainder[fd]);
		return (NULL);
	}
	if (buffer == NULL)
		return (NULL);
	read_str = read_into_buffer(fd, remainder[fd], buffer);
	dangling_pointers(&buffer);
	if (read_str == NULL)
		return (NULL);
	remainder[fd] = extract_remainder(read_str);
	return (read_str);
}

char	*read_into_buffer(int fd, char *str_remainder, char *buffer)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read >= 1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			dangling_pointers(&str_remainder);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!str_remainder)
			str_remainder = ft_strdup_gnl("");
		temp = ft_strjoin_gnl(str_remainder, buffer);
		free(str_remainder);
		str_remainder = temp;
		if (ft_strchr_gnl(buffer, '\n'))
			break ;
	}
	return (str_remainder);
}

char	*extract_remainder(char *read_str)
{
	char	*remainder;
	int		i;

	i = 0;
	while (read_str[i] != '\0' && read_str[i] != '\n')
		i++;
	if (read_str[i] == '\0' || read_str[i + 1] == '\0')
		return (NULL);
	remainder = ft_substr_gnl(read_str, i + 1, ft_strlen_gnl(read_str) - i);
	if (remainder == NULL)
		dangling_pointers(&remainder);
	read_str[i + 1] = '\0';
	return (remainder);
}

void	dangling_pointers(char **ptr)
{
	free (*ptr);
	*ptr = NULL;
}
