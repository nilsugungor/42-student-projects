/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:26:27 by ngungor           #+#    #+#             */
/*   Updated: 2025/05/28 16:13:40 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (0);
	while (s1[i] && s2[i] && i < size - 1)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			break ;
		i++;
	}
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}

/*#include <stdio.h>
int main()
{
    printf("%d\n", ft_strncmp("123456", "234567", 3));
    printf("%d\n", ft_strncmp("123456", "123456", 7));
    printf("%d\n", ft_strncmp("123456", "934567", 1));

}*/
