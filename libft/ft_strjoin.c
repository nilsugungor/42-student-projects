/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:48:38 by ngungor           #+#    #+#             */
/*   Updated: 2025/05/28 15:42:05 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*s1: The prefix string.
s2: The suffix string*/

/*return value: The new string.
NULL if the allocation fails.*/

/*Allocates memory (using malloc(3)) and returns a
new string, which is the result of concatenating
’s1’ and ’s2’*/
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstring;
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	newstring = (char *)malloc(len1 + len2 + 1);
	if (!newstring)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		newstring[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
		newstring[i++] = s2[j++];
	newstring[i] = '\0';
	return (newstring);
}
