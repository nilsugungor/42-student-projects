/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:06:10 by ngungor           #+#    #+#             */
/*   Updated: 2025/05/28 15:59:58 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	i = 0;
	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	if (d == s || n == 0)
		return (dest);
	if (d > s && d < s + n)
	{
		while (n--)
			d[n] = s[n];
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

/*int	main(void)
{
	char strsource[50] = "nilsu gungor is the best";
	char strdest[50];
	ft_memmove(strdest, strsource, 50);
	printf("after memcpy: ");
	for (int i = 0; i < 50; i++)
	{
		printf("%c ", strdest[i]);
	}
	return (0);
}*/
