/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:04:53 by ngungor           #+#    #+#             */
/*   Updated: 2025/05/28 15:54:42 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = s1;
	ptr2 = s2;
	while (n--)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		ptr1++;
		ptr2++;
	}
	return (0);
}

/*int main() {
    const char *str1 = "Hello";
    const char *str2 = "Hello, world!";
    
    // Compare the first 5 bytes of both strings
    int result = memcmp(str1, str2, 6);

    if (result == 0) {
        printf("The first 5 bytes are equal.\n");
    } else if (result > 0) {
        printf("The first 5 bytes of str1 are greater than str2.\n");
    } else {
        printf("The first 5 bytes of str1 are less than str2.\n");
    }

    return 0;
}*/
