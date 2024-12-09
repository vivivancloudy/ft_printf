/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdinh <thdinh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:06:15 by thdinh            #+#    #+#             */
/*   Updated: 2024/12/09 15:25:51 by thdinh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	type(char input, va_list args)
{
	if (input == 'c')
		return (ft_printf_char(va_arg(args, int)));
	if (input == 's')
		return (ft_printf_str(va_arg(args, char *)));
	if (input == 'p')
		return (ft_printf_ptr(va_arg(args, void *)));
	if (input == 'd' || input == 'i')
		return (ft_printf_int(va_arg(args, int)));
	if (input == 'u')
		return (ft_printf_unsigned(va_arg(args, unsigned int)));
	if (input == 'x')
		return (ft_printf_hex(va_arg(args, unsigned int), 0));
	if (input == 'X')
		return (ft_printf_hex(va_arg(args, unsigned int), 1));
	if (input == '%')
		return (ft_printf_percent());
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			count += type(format[i], args);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

/*int	main(void)
{
	ft_printf("Hello, %s! Your score is %d and your pointer is %p.\n", "Alice", 42, &main);
	return (0);
}*/
