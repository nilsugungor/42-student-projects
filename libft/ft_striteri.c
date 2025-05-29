/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:36:43 by ngungor           #+#    #+#             */
/*   Updated: 2025/05/28 16:15:34 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
// Callback functions for testing

// Capitalize all lowercase letters
void to_upper(unsigned int i, char *c)
{
    (void)i;
    if (*c >= 'a' && *c <= 'z')
        *c = *c - 32;
}

// Add index to each character (simple manipulation)
void add_index(unsigned int i, char *c)
{
    *c = *c + i;
}

// Turn all characters into underscores
void to_underscore(unsigned int i, char *c)
{
    (void)i;
    *c = '_';
}

// Tests
void test_ft_striteri()
{
    char s1[] = "hello";
    ft_striteri(s1, to_upper);
    if (strcmp(s1, "HELLO") == 0)
        printf("Test 1 passed (to_upper)\n");
    else
        printf("Test 1 failed: expected 'HELLO', got '%s'\n", s1);

    char s2[] = "abc";
    ft_striteri(s2, add_index);  // 'a'+0, 'b'+1='c', 'c'+2='e'
    if (strcmp(s2, "ace") == 0)
        printf("Test 2 passed (add_index)\n");
    else
        printf("Test 2 failed: expected 'ace', got '%s'\n", s2);

    char s3[] = "openai";
    ft_striteri(s3, to_underscore);
    if (strcmp(s3, "______") == 0)
        printf("Test 3 passed (to_underscore)\n");
    else
        printf("Test 3 failed: expected '______', got '%s'\n", s3);

    char s4[] = "";
    ft_striteri(s4, to_upper);  // Should do nothing
    if (strcmp(s4, "") == 0)
        printf("Test 4 passed (empty string)\n");
    else
        printf("Test 4 failed: expected '', got '%s'\n", s4);

    // NULL string
    ft_striteri(NULL, to_upper);  // Should not crash
    printf("Test 5 passed (NULL string, no crash)\n");

    // NULL function
    char s6[] = "hello";
    ft_striteri(s6, NULL);  // Should do nothing
    if (strcmp(s6, "hello") == 0)
        printf("Test 6 passed (NULL function, no change)\n");
    else
        printf("Test 6 failed: expected 'hello', got '%s'\n", s6);
}

int main()
{
    test_ft_striteri();
    return 0;
}*/
