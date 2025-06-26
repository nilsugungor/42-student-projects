/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:30:27 by ngungor           #+#    #+#             */
/*   Updated: 2025/06/04 13:30:28 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	substring = (char *)malloc(len + 1);
	if (!substring)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

static void	ft_strcpy_join(char *dest, const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (s1)
	{
		while (s1[i])
		{
			dest[i] = s1[i];
			i++;
		}
	}
	j = 0;
	if (s2)
	{
		while (s2[j])
		{
			dest[i++] = s2[j++];
		}
	}
	dest[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstring;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	len1 = 0;
	len2 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	if (s2)
		len2 = ft_strlen(s2);
	newstring = (char *)malloc(len1 + len2 + 1);
	if (!newstring)
		return (NULL);
	ft_strcpy_join(newstring, s1, s2);
	return (newstring);
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

int	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}
