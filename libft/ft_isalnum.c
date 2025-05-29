/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:59:23 by ngungor           #+#    #+#             */
/*   Updated: 2025/05/28 16:19:03 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
	{
		return (1);
	}
	return (0);
}

// int main(void)
// {  
//     printf("%d\n", ft_isalnum(9));
//     printf("%d\n", ft_isalnum('9'));
//     printf("%d\n", ft_isalnum('a'));
//     printf("%d\n", ft_isalnum('Z'));
//     printf("%d\n", ft_isalnum('%'));
//     printf("%d\n", ft_isalnum(' '));
//     printf("%d\n", ft_isalnum('z'));
//     printf("%d\n", ft_isalnum('A'));
// }
