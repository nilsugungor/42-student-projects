/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:31:17 by ngungor           #+#    #+#             */
/*   Updated: 2025/05/28 16:59:40 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Depending on your current operating system, the ’calloc’ function’s
behavior may differ from its man page description. Follow this
rule instead: If nmemb or size is 0, then calloc() returns a unique
pointer value that can be successfully passed to free().*/

/*
    nmemb − It represents the number of element to be allocated.
    size − It represents the size of each element.*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	size_t			i;
	unsigned char	*p;

	i = 0;
	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(0);
		return (ptr);
	}
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	p = (unsigned char *)ptr;
	while (i < size * nmemb)
	{
		p[i] = 0;
		i++;
	}
	return (ptr);
}
