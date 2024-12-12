/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdinh <thdinh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:07:05 by thdinh            #+#    #+#             */
/*   Updated: 2024/12/09 15:25:13 by thdinh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printout(unsigned int nb)
{
	if (nb >= 10)
		printout(nb / 10);
	ft_putchar_fd((nb % 10) + '0', 1);
}

int	ft_printf_unsigned(unsigned int nb)
{
	int				i;
	unsigned int	temp;

	if (nb == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	printout(nb);
	i = 0;
	temp = nb;
	while (temp > 0)
	{
		temp = temp / 10;
		i++;
	}
	return (i);
}
