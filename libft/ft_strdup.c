/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:18:35 by ngungor           #+#    #+#             */
/*   Updated: 2025/05/28 14:19:36 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

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
