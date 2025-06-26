/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:31:51 by ngungor           #+#    #+#             */
/*   Updated: 2025/05/28 16:41:48 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
	{
		return ((char *)big);
	}
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while ((i + j) < len && little[j] != '\0' && big[i + j] == little[j])
		{
			j++;
		}
		if (little[j] == '\0')
		{
			return ((char *)(big + i));
		}
		i++;
	}
	return (0);
}

/*int main(void)
{
    const char *haystack = "Hello, world!";
    const char *needle1 = "world";
    const char *needle2 = "planet";
    const char *needle3 = "";
    size_t len = 13;

    char *result;

    // Test 1: Needle found within len
    result = ft_strnstr(haystack, needle1, len);
    if (result)
        printf("Found '%s' at position %ld\n", needle1, result - haystack);
    else
        printf("'%s' not found in first %zu characters.\n", needle1, len);

    // Test 2: Needle not found
    result = ft_strnstr(haystack, needle2, len);
    if (result)
        printf("Found '%s' at position %ld\n", needle2, result - haystack);
    else
        printf("'%s' not found in first %zu characters.\n", needle2, len);

    // Test 3: Empty needle (should return haystack)
    result = ft_strnstr(haystack, needle3, len);
    if (result)
        printf("Empty needle, returned haystack: \"%s\"\n", result);
    else
        printf("Empty needle returned NULL (shouldn't happen).\n");

    return 0;
}*/
