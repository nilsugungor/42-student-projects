/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:56:19 by ngungor           #+#    #+#             */
/*   Updated: 2025/05/28 13:56:31 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str <= '9' && *str >= '0')
	{
		result = (result * 10) + *str - 48;
		str++;
	}
	return (result * sign);
}
// int main(void)
// {
//     int x, y, z;
//     char str[] = "he   llo 4335";
//     char str1[] = "+-4335";
//     char str2[] = "4335";
//     x = ft_atoi(str);
//     y = ft_atoi(str1);
//     z = ft_atoi(str2);
//     printf("%d", x);
//     printf("%d", y);
//     printf("%d", z);
// }
