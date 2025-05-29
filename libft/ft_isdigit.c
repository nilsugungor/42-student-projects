/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:06:24 by ngungor           #+#    #+#             */
/*   Updated: 2025/05/28 15:51:32 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
	{
		return (1);
	}
	return (0);
}
// int main(void)
// {
//     printf("%d\n", ft_isdigit(9));
//     printf("%d\n", ft_isdigit(0));
//     printf("%d\n", ft_isdigit(-3));
//     printf("%d\n", ft_isdigit('3'));
//     printf("%d\n", ft_isdigit('%'));
//     printf("%d\n", ft_isdigit('4'));
// }
