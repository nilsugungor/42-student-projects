/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:44:19 by ngungor           #+#    #+#             */
/*   Updated: 2025/05/28 15:55:41 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*keeper;

	keeper = NULL;
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
		{
			keeper = (char *)s;
		}
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (keeper);
}

/*int main() {

    const char *str = "Hello, worldo!";
    char ch = 'o';

    // Use strchr to find the first occurrence of 'o'
    char *result = ft_strrchr(str, ch);

    if (result != NULL) {
        printf("Found '%c' at position %ld\n", ch, result - str);
    } else {
        printf("Character '%c' not found.\n", ch);
    }

    return 0;
}*/
