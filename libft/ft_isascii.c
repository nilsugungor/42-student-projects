/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:04:44 by ngungor           #+#    #+#             */
/*   Updated: 2025/05/28 14:05:50 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

// int main(void)
// {
//     printf("%d\n", ft_isascii('0'));
//     printf("%d\n", ft_isascii('a'));
//     printf("%d\n", ft_isascii(' '));
//     printf("%d\n", ft_isascii('\t'));
//     printf("%d\n", ft_isascii(130));
//     printf("%d\n", ft_isascii(555));
//     printf("%d\n", ft_isascii(-17));
// }
