/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:11:54 by ngungor           #+#    #+#             */
/*   Updated: 2025/05/28 14:12:22 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_tolower(int c)
{
	if (c <= 90 && c >= 65)
	{
		c = c + 32;
	}
	return (c);
}
// #include <stdio.h>
// int main(void)
// {
//     char result = ft_tolower('A');
//     printf("%c\n", result);
//     return 0;
// }
