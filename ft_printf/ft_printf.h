/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:47:16 by ngungor           #+#    #+#             */
/*   Updated: 2025/05/30 17:04:05 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

char		*ft_uitoa(unsigned int n);
int			ft_putstr(const char *s);
size_t		ft_strlen(const char *s);
int			ft_printf(const char *string, ...);
int			ft_putnbr(int n);
int			ft_puthex(uintptr_t n, int uppercase);
int			print_string(va_list args);
int			print_unumber(va_list args);
int			print_number(va_list args);
int			print_hex(va_list args, int uppercase);
int			print_pointer(va_list args);
int			print_char(va_list args);

#endif
