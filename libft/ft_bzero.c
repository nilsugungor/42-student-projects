/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:14:39 by ngungor           #+#    #+#             */
/*   Updated: 2025/05/28 16:57:57 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	int				zero;

	zero = 0;
	ptr = s;
	while (n > 0)
	{
		*ptr = (unsigned char)zero;
		ptr++;
		n--;
	}
}

/*int	main(void)
{
	char str[50] = "hello world!";
	ft_bzero(str, 5);
	printf("after bzero: ");
	for (int i = 0; i < 50; i++)
	{
		printf("%c ", str[i]);
	}
}*/
