/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:11:04 by ngungor           #+#    #+#             */
/*   Updated: 2025/05/28 14:02:38 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	i = 0;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

/*int main() {

    char dest[10];
    const char *src = "Hello, world!";
    
    size_t copied = ft_strlcpy(dest, src, (sizeof(dest) - 1));
    
    printf("Copied string: %s\n", dest);
    printf("Total length of src: %zu\n", copied);
    
    if (copied >= sizeof(dest)) {
        printf("Warning: String was truncated!\n");
    }
    return 0;
}*/
