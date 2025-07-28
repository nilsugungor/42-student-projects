/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:57:38 by ngungor           #+#    #+#             */
/*   Updated: 2025/07/08 11:58:05 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*leftover[MAX_FD];
	char		*buf;
	char		*line;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd >= MAX_FD)
	{
		free(leftover[fd]);
		free(buf);
		leftover[fd] = NULL;
		line = NULL;
		return (NULL);
	}
	if (!buf)
		return (NULL);
	line = fill_line_buffer(fd, leftover[fd], buf);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	leftover[fd] = set_line(line);
	return (line);
}

char	*set_line(char *line_buffer)
{
	char	*leftover;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == 0)
		return (NULL);
	leftover = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*leftover == 0)
	{
		free(leftover);
		leftover = NULL;
	}
	line_buffer[i + 1] = 0;
	return (leftover);
}

char	*fill_line_buffer(int fd, char *leftover, char *buf)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(leftover);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buf[bytes_read] = 0;
		if (!leftover)
			leftover = ft_strdup("");
		temp = leftover;
		leftover = ft_strjoin(temp, buf);
		free(temp);
		temp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (leftover);
}

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(s) + 1;
	p = (char *)malloc(size * sizeof(char));
	if (!p)
		return (NULL);
	while (i < size)
	{
		p[i] = s[i];
		i++;
	}
	return (p);
}

// int	main(int argc, char **argv)
// {
// 	#include <stdio.h>
// 	int		fd;
// 	char	*line;
// 	int		i;
//
// 	if (argc < 2)
// 	{
// 		printf("Usage: %s <file1> [file2 ...]\n", argv[0]);
// 		return (1);
// 	}
//
// 	for (int file_index = 1; file_index < argc; file_index++)
// 	{
// 		fd = open(argv[file_index], O_RDONLY);
// 		if (fd < 0)
// 		{
// 			perror("Error opening file");
// 			continue;
// 		}
// 		printf("=== Reading file: %s ===\n", argv[file_index]);
// 		i = 0;
// 		while ((line = get_next_line(fd)) != NULL)
// 		{
// 			printf("Line %d: [%s]", ++i, line);  // line may contain \n
// 			free(line);
// 		}
// 		printf("EOF reached.\n\n");
// 		close(fd);
// 	}
// 	return (0);
// }
