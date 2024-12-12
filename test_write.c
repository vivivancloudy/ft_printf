/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdinh <thdinh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:30:58 by thdinh            #+#    #+#             */
/*   Updated: 2024/12/12 13:31:14 by thdinh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "ft_printf.h"


int mock_ft_putchar_fd(char c, int fd)
{
    (void)c; 
    (void)fd;
    errno = EIO;
    return -1;
}

void test_ft_printf_write_fail()
{
    #define ft_putchar_fd mock_ft_putchar_fd

    void *ptr = NULL;
    int result = ft_printf("%p\n", ptr);

    if (result == -1)
        printf("Test passed: ft_printf returned -1 on write failure\n");
    else
        printf("Test failed: ft_printf did not return -1 on write failure\n");

    #undef ft_putchar_fd
}

/*int main()
{
    test_ft_printf_write_fail();
    return 0;
}*/
