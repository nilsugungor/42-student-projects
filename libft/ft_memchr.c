/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:59:34 by ngungor           #+#    #+#             */
/*   Updated: 2025/05/28 16:11:25 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		target;

	ptr = s;
	target = (unsigned char)c;
	while (n--)
	{
		if (*ptr == target)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}
