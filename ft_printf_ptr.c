/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdinh <thdinh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:07:30 by thdinh            #+#    #+#             */
/*   Updated: 2024/12/09 13:40:24 by thdinh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_ptr_to_hex(void *ptr, char *buffer)
{
	unsigned long	addr;
	int				i;

	addr = (unsigned long)ptr;
	i = 0;
	if (addr == 0)
	{
		buffer[i++] = '0';
		buffer[i++] = '0';
		buffer[i++] = 'x';
	}
	else
	{
		while (addr > 0)
		{
			buffer[i++] = "0123456789abcdef"[addr % 16];
			addr /= 16;
		}
	}
	return (i);
}

int	ft_printf_ptr(void *ptr)
{
	char	buffer[18];
	int		len;

	len = convert_ptr_to_hex(ptr, buffer);
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	while (--len >= 0)
		ft_putchar_fd(buffer[len], 1);
	return (len + 2);
}
