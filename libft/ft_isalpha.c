/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:25:05 by ngungor           #+#    #+#             */
/*   Updated: 2025/05/28 14:25:43 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c <= 122 && c >= 97) || (c <= 90 && c >= 65))
	{
		return (1);
	}
	return (0);
}
// int main(void)
// {
//     printf("%d\n", ft_isalpha('a'));
//     printf("%d\n", ft_isalpha('A'));
//     printf("%d\n", ft_isalpha('9'));
//     printf("%d\n", ft_isalpha('%'));
// }
