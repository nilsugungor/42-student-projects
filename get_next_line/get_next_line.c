/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:30:11 by ngungor           #+#    #+#             */
/*   Updated: 2025/06/04 14:02:02 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*leftover;
	char	*newline_position;
	char	*new_line;
	char	buf[BUFFER_SIZE + 1];
	ssize_t	buf_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while ((newline_position = ft_strchr(leftover, '\n')) == NULL)
	{
		buf_read = read(fd, buf, BUFFER_SIZE);
		if (buf_read <= 0)
			break ;
		buf[buf_read] = '\0';
		leftover = ft_strjoin(leftover, buf);	
	}
	new_line = extract_line_from_leftover(&leftover);
	return (new_line);
}

char	*extract_line_from_leftover(char **leftover_ptr)
{
	
	free(*leftover_ptr);

}






















