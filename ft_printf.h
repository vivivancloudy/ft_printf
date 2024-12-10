/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdinh <thdinh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:08:07 by thdinh            #+#    #+#             */
/*   Updated: 2024/12/09 15:44:31 by thdinh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
#include <stdlib.h>
# include <unistd.h>

int		  ft_printf(const char *input, ...);
int 	  ft_printf_ptr(void *ptr);
int 	  ft_printf_unsigned(unsigned int nb);
int 	  ft_printf_str(char *str);
int 	  ft_printf_int(int n);
int 	  ft_printf_char(char c);
int     ft_printf_percent(void);
int 	  ft_printf_hex(unsigned int n, int uppercase);
int  	  ft_putchar_fd(char c, int fd);
int  	  ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
char	  *ft_itoa(int n);

#endif
