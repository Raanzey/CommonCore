/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:52:25 by yozlu             #+#    #+#             */
/*   Updated: 2024/11/10 00:37:15 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF
# define PRINTF

# include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int ft_putchar(char c);
int  ft_putstr(char *s);
int ft_putnbr(long n);
int ft_putnbr_unsigned(unsigned long n);
int ft_putnbr_hexe(unsigned int n, char x);
char *ft_strchr(const char *s, int c);
size_t ft_strlen(const char *s);
int ft_printf_pointer(void *ptr);

#endif