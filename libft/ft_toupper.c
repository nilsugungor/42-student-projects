/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:14:44 by ngungor           #+#    #+#             */
/*   Updated: 2025/05/28 14:15:08 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_toupper(int c)
{
	if (c <= 122 && c >= 97)
	{
		c = c - 32;
	}
	return (c);
}
//#include <stdio.h>
// int main(void)
// {
//     char result = ft_toupper('a');
//     printf("%c\n", result);
//     return 0;
// }
