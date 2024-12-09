/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdinh <thdinh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:07:18 by thdinh            #+#    #+#             */
/*   Updated: 2024/12/09 12:59:00 by thdinh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_to_hex(unsigned int n, char *buffer, const char *hex_digits)
{
	int	i;

	i = 0;
	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = hex_digits[n % 16];
			n /= 16;
		}
	}
	return (i);
}

int	ft_printf_hex(unsigned int n, int uppercase)
{
	const char	*hex_digits;
	char		buffer[9];
	int			len;

	if (uppercase)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	len = convert_to_hex(n, buffer, hex_digits);
	while (--len >= 0)
		ft_putchar_fd(buffer[len], 1);
	return (len);
}
