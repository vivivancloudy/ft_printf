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
	char	buffer[16];
	int		len;
	int		i;

	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	len = convert_ptr_to_hex(ptr, buffer);
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	i = len - 1;
	while (i >= 0)
	{
		ft_putchar_fd(buffer[i], 1);
		i--;
	}
	return (len + 2);
}
