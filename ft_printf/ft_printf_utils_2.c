/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:54:52 by ngungor           #+#    #+#             */
/*   Updated: 2025/05/30 17:05:07 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putstr(const char *s)
{
	int	count;

	count = 0;
	if (s)
	{
		while (*s)
		{
			write(1, s, 1);
			s++;
			count++;
		}
	}
	return (count);
}

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

static int	ft_len(unsigned int n)
{
	int	len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char		*strinteger;
	int			len;

	len = ft_len(n);
	strinteger = (char *)malloc(len + 1);
	if (!strinteger)
		return (NULL);
	strinteger[len] = '\0';
	while (--len >= 0)
	{
		strinteger[len] = (n % 10) + '0';
		n /= 10;
	}
	return (strinteger);
}
