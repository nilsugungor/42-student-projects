/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:59:50 by ngungor           #+#    #+#             */
/*   Updated: 2025/05/28 16:20:16 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n > 0)
	{
		*p = (unsigned char)c;
		p++;
		n--;
	}
	return (s);
}

/*int	main(void)
{
	char str[50] = "hello world!";
	printf("before memset: %s\n", str);
	ft_memset(str, 0, 5);
	printf("after memset: ");
	for (int i = 0; i < 50; i++)
	{
		if (str[i] == '\0')
			printf("\\0 ");
		else
			printf("%c ", str[i]);
	}
	printf("\n");

	return (0);
}*/
