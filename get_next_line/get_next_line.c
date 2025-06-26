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

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*leftover;
	int			newline_index;
	char		*new_line;
	char		*buf;
	ssize_t		bytes_read;
	char		*joined;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	new_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buf);
		return (NULL);
	}
	if (leftover)
	{
		newline_index = ft_strchr(leftover, '\n');
		if (newline_index >= 0)
		{
			new_line = extract_line(leftover, newline_index);
			update_leftover_after_newline(&leftover, newline_index);
			free(buf);
			return (new_line);
		}
	}
	while ((bytes_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes_read] = '\0';
		joined = ft_strjoin(leftover, buf);
		if (!joined)
		{
			free(leftover);
			leftover = NULL;
			free(buf);
			return (NULL);
		}
		free(leftover);
		leftover = joined;
		newline_index = ft_strchr(leftover, '\n');
		if (newline_index >= 0)
		{
			new_line = extract_line(leftover, newline_index);
			update_leftover_after_newline(&leftover, newline_index);
			free(buf);
			return (new_line);
		}
	}
	if (bytes_read == -1)
	{
		free(leftover);
		leftover = NULL;
		free(buf);
		return (NULL);
	}
	if (leftover && *leftover)
	{
		new_line = ft_strdup(leftover);
		free(leftover);
		leftover = NULL;
		free(buf);
		return (new_line);
	}
	free(buf);
	return (NULL);
}

void	update_leftover_after_newline(char **leftover, int newline_index)
{
	char	*temp;
	int		leftover_len;

	if (!leftover || !*leftover)
		return ;
	leftover_len = ft_strlen(*leftover);
	if (newline_index + 1 >= leftover_len)
	{
		free(*leftover);
		*leftover = NULL;
		return ;
	}
	temp = ft_substr(*leftover, newline_index + 1, leftover_len 
			- (newline_index + 1));
	free(*leftover);
	*leftover = temp;
}

char	*extract_line(char *leftover, int newline_index)
{
	int		i;
	char	*extracted_line;

	extracted_line = malloc(newline_index + 2);
	if (!extracted_line)
		return (NULL);
	i = 0;
	while (i < newline_index + 1)
	{
		extracted_line[i] = leftover[i];
		i++;
	}
	extracted_line[newline_index + 1] = '\0';
	return (extracted_line);
}

int	ft_strchr(const char *s, int c)
{
	int	count;

	count = 0;
	if (!s)
		return (-1);
	while (s[count])
	{
		if (s[count] == (unsigned char)c)
		{
			return (count);
		}
		count++;
	}
	return (-1);
}

int	ft_strlen(const char *s)
{
	int	count;
	
	count = 0;
	while (s[count])
		count++;
	return (count);
}
