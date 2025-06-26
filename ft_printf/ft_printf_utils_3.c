/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:13:10 by ngungor           #+#    #+#             */
/*   Updated: 2025/05/31 16:13:13 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_pointer(va_list args)
{
	void	*ptr;
	int		printed;

	ptr = va_arg(args, void *);
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	printed = write(1, "0x", 2);
	printed += ft_puthex((uintptr_t)ptr, 0);
	return (printed);
}

int	print_hex(va_list args, int uppercase)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	return (ft_puthex(num, uppercase));
}

int	print_number(va_list args)
{
	int	i;

	i = va_arg(args, int);
	return (ft_putnbr(i));
}

int	print_unumber(va_list args)
{
	char			*num_str;
	unsigned int	u;
	int				printed;

	u = va_arg(args, unsigned int);
	num_str = ft_uitoa(u);
	if (!num_str)
		return (0);
	printed = ft_putstr(num_str);
	free(num_str);
	return (printed);
}

int	print_string(va_list args)
{
	const char	*s;

	s = va_arg(args, const char *);
	if (!s)
		s = "(null)";
	return (ft_putstr(s));
}
