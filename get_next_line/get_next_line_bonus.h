/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:59:14 by ngungor           #+#    #+#             */
/*   Updated: 2025/07/08 12:00:25 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# include <fcntl.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*set_line(char *line_buffer);
char	*fill_line_buffer(int fd, char *leftover, char *buf);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
