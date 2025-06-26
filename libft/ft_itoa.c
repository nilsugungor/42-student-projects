/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 11:06:08 by ngungor           #+#    #+#             */
/*   Updated: 2025/05/28 16:58:51 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	len;

	if (n <= 0)
	{
		len = 1;
	}
	else
	{
		len = 0;
	}
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*strinteger;
	int			len;
	long		nb;

	nb = n;
	len = ft_len(n);
	strinteger = (char *)malloc(len + 1);
	if (!strinteger)
		return (NULL);
	strinteger[len] = '\0';
	if (nb < 0)
	{
		strinteger[0] = '-';
		nb = -nb;
	}
	while (--len >= 0 && strinteger[len] != '-')
	{
		strinteger[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (strinteger);
}
