/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:07:39 by ngungor           #+#    #+#             */
/*   Updated: 2025/05/28 14:08:04 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
// int main()
// {
//     printf("%d\n", ft_isprint('9'));
//     printf("%d\n", ft_isprint('0'));
//     printf("%d\n", ft_isprint('z'));
//     printf("%d\n", ft_isprint('a'));
//     printf("%d\n", ft_isprint(' '));
//     printf("%d\n", ft_isprint(7));
//     printf("%d\n", ft_isprint(127));
//     printf("%d\n", ft_isprint('\0'));
// }
