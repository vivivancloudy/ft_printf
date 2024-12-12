/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdinh <thdinh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:45:44 by thdinh            #+#    #+#             */
/*   Updated: 2024/12/09 15:45:48 by thdinh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> 

int	main(void)
{
	int	len;

	len = ft_printf("Character test: %c\n", 'A');
	printf("ft_printf returned: %d\n", len);
	len = ft_printf("String test: %s\n", "Hello, world!");
	printf("ft_printf returned: %d\n", len);
	len = ft_printf("Pointer test: %p\n", (void *)main);
	printf("ft_printf returned: %d\n", len);
	len = ft_printf("Integer test: %d\n", 42);
	printf("ft_printf returned: %d\n", len);
	len = ft_printf("Unsigned integer test: %u\n", 42);
	printf("ft_printf returned: %d\n", len);
	len = ft_printf("Hexadecimal test (lowercase): %x\n", 255);
	printf("ft_printf returned: %d\n", len);
	len = ft_printf("Hexadecimal test (uppercase): %X\n", 255);
	printf("ft_printf returned: %d\n", len);
	len = ft_printf("Percentage test: %%\n");
	printf("ft_printf returned: %d\n", len);
	printf("Original printf test: %d\n", 42);
	void *ptr = NULL;
	ft_printf("%p\n", ptr);
	return (0);
}
