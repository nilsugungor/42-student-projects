/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:23:47 by ngungor           #+#    #+#             */
/*   Updated: 2025/05/30 17:04:47 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

static int	norminettele(char string, va_list args)
{
	int	printed;

	printed = 0;
	if (string == 'c')
		printed += print_char(args);
	else if (string == 'p')
		printed += print_pointer(args);
	else if (string == 'x')
		printed += print_hex(args, 0);
	else if (string == 'X')
		printed += print_hex(args, 1);
	else if (string == 'd' || string == 'i')
		printed += print_number(args);
	else if (string == 'u')
		printed += print_unumber(args);
	else if (string == 's')
		printed += print_string(args);
	else if (string == '%')
		printed += write(1, "%", 1);
	else
	{
		printed += write(1, "%", 1);
		printed += write(1, &string, 1);
	}
	return (printed);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		printed;

	va_start(args, string);
	printed = 0;
	if (!string)
		return (-1);
	while (*string)
	{
		if (*string != '%')
		{
			printed += write(1, string, 1);
			string++;
		}
		else if (*string == '%')
		{
			string++;
			printed += norminettele(*string, args);
			string++;
		}
	}
	va_end(args);
	return (printed);
}
/*
int	main(void)
{
	char	*null_str;

	int	ret_printf
	int	ret_ft;

	null_str = NULL;
	printf("---- Additional Test: NULL string with %%s ----\n");
	ret_printf = printf("printf:    %s gdfgsdfgdsfg \n", null_str);
	ret_ft = ft_printf("ft_printf: %s gdfgsdfgdsfg \n", null_str);
	printf("Return values -> printf: %d, ft_printf: %d\n\n", ret_printf,
			ret_ft);
	// Test 1: NULL string (passing NULL as argument to %s)
	printf("---- Test 1: NULL string ----\n");
	ret_printf = printf(NULL);
	ret_ft = ft_printf(NULL);
	printf("Return values -> printf: %d, ft_printf: %d\n\n", ret_printf,
			ret_ft);
	printf(NULL);
	ft_printf(NULL);
	// Test 2: Printing 0 with %d
	printf("---- Test 2: 0 integer ----\n");
	ret_printf = printf(0);
	ret_ft = ft_printf(0);
	printf("Return values -> printf: %d, ft_printf: %d\n\n", ret_printf,
			ret_ft);
	printf(0);
	ft_printf(0);
	// Test 3: Invalid format specifier %g (if not supported)
	printf("---- Test 3: Invalid format %%g ----\n");
	ret_printf = printf("abc: %b\n", 3.14);
	ret_ft = ft_printf("bla: %b\n", 3.14);
	printf("Return values -> printf: %d, ft_printf: %d\n\n", ret_printf,
			ret_ft);
	// Test 4: Completely unknown format like %j
	printf("---- Test 4: Unknown format %%j ----\n");
	ret_printf = printf("printf:    %j\n", 123);
	ret_ft = ft_printf("ft_printf: %j\n", 123);
	printf("Return values -> printf: %d, ft_printf: %d\n\n", ret_printf,
			ret_ft);
	printf("---- Test: Empty String ----\n");
	ret_printf = printf("printf:    '%s'\n", "");
	ret_ft = ft_printf("ft_printf: '%s'\n", "");
	printf("Return values -> printf: %d, ft_printf: %d\n\n", ret_printf,
			ret_ft);
	// Test smallest integer (INT_MIN)
	printf("---- Test: Smallest Integer (INT_MIN) ----\n");
	ret_printf = printf("printf:    %d\n", INT_MIN);
	ret_ft = ft_printf("ft_printf: %d\n", INT_MIN);
	printf("Return values -> printf: %d, ft_printf: %d\n\n", ret_printf,
			ret_ft);
	// Test %c with various characters
	printf("---- Test: Character %%c ----\n");
	ret_printf = printf("printf:    %c %c %c\n", 'A', ' ', 'z');
	ret_ft = ft_printf("ft_printf: %c %c %c\n", 'A', ' ', 'z');
	printf("Return values -> printf: %d, ft_printf: %d\n\n", ret_printf,
			ret_ft);
	// Test %i with positive and negative integers
	printf("---- Test: Integer %%i ----\n");
	ret_printf = printf("printf:    %i %i %i\n", 42, -42, 0);
	ret_ft = ft_printf("ft_printf: %i %i %i\n", 42, -42, 0);
	printf("Return values -> printf: %d, ft_printf: %d\n\n", ret_printf,
			ret_ft);
	// Test %d same as %i
	printf("---- Test: Integer %%d ----\n");
	ret_printf = printf("printf:    %d %d %d\n", 2147483647, -2147483647, 0);
	ret_ft = ft_printf("ft_printf: %d %d %d\n", 2147483647, -2147483647, 0);
	printf("Return values -> printf: %d, ft_printf: %d\n\n", ret_printf,
			ret_ft);
	// Test %u unsigned integers
	printf("---- Test: Unsigned %%u ----\n");
	ret_printf = printf("printf:    %u %u %u\n", 0, 1234567890u, UINT_MAX);
	ret_ft = ft_printf("ft_printf: %u %u %u\n", 0, 1234567890u, UINT_MAX);
	printf("Return values -> printf: %d, ft_printf: %d\n\n", ret_printf,
			ret_ft);
	// Test %x lowercase hex
	printf("---- Test: Hexadecimal %%x ----\n");
	ret_printf = printf("printf:    %x %x %x\n", 0, 48879, UINT_MAX);
	ret_ft = ft_printf("ft_printf: %x %x %x\n", 0, 48879, UINT_MAX);
	printf("Return values -> printf: %d, ft_printf: %d\n\n", ret_printf,
			ret_ft);
	// Test %X uppercase hex
	printf("---- Test: Hexadecimal %%X ----\n");
	ret_printf = printf("printf:    %X %X %X\n", 0, 48879, UINT_MAX);
	ret_ft = ft_printf("ft_printf: %X %X %X\n", 0, 48879, UINT_MAX);
	printf("Return values -> printf: %d, ft_printf: %d\n\n", ret_printf,
			ret_ft);
	// Test %s with normal and NULL strings
	printf("---- Test: String %%s ----\n");
	ret_printf = printf("printf:    '%s' '%s'\n", "Hello, World!", null_str);
	ret_ft = ft_printf("ft_printf: '%s' '%s'\n", "Hello, World!", null_str);
	printf("Return values -> printf: %d, ft_printf: %d\n\n", ret_printf,
			ret_ft);
	// Test multiple identical conversions in sequence (%d %d %d)
	printf("---- Test: Multiple identical conversions in sequence ----\n");
	ret_printf = printf("printf:    %d %d %d %d\n", 1, 2, 3, 4);
	ret_ft = ft_printf("ft_printf: %d %d %d %d\n", 1, 2, 3, 4);
	printf("Return values -> printf: %d, ft_printf: %d\n\n", ret_printf,
			ret_ft);
	// Test multiple identical conversions for %s
	printf("---- Test: Multiple identical %%s conversions in sequence ----\n");
	ret_printf = printf("printf:    %s %s %s\n", "foo", "bar", "baz");
	ret_ft = ft_printf("ft_printf: %s %s %s\n", "foo", "bar", "baz");
	printf("Return values -> printf: %d, ft_printf: %d\n\n", ret_printf,
			ret_ft);
	return (0);
}*/
