/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nil <nil@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:23:47 by ngungor           #+#    #+#             */
/*   Updated: 2025/07/07 00:27:26 by nil              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

static int	handle_formatter(char string, va_list args)
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