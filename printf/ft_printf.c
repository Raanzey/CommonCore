/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:29:39 by yozlu             #+#    #+#             */
/*   Updated: 2024/11/10 22:38:41 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int type_control(char c, va_list args)
{
    if (c == 'c')
        return(ft_putchar(va_arg(args, int))); 
    else if (c == 's')
        return(ft_putstr(va_arg(args, char*)));  
    else if (c == 'p')
        return(ft_printf_pointer(va_arg(args, void*)));
    else if (c == 'd' || c == 'i')
        return(ft_putnbr(va_arg(args, int)));  
    else if (c == 'u')
        return(ft_putnbr(va_arg(args, unsigned int)));  
    else if (c == 'x')
        return(ft_putnbr_hexe(va_arg(args, unsigned int), 'x')); 
    else if (c == 'X')
        return(ft_putnbr_hexe(va_arg(args, unsigned int), 'X')); 
    else if (c == '%')
        return(ft_putchar('%')); 
    else
        return 0; 
}

int ft_printf(const char *type, ...)
{
    int result = 0;
    int i = 0;
    va_list args;
    va_start(args, type);  

    while (type[i])  
    {
        if (type[i] == '%')  
        {
            i++; 
            result += type_control(type[i], args);  
        }        
        else  
        {
            ft_putchar(type[i]);
            result++;  
        }
        i++;  
    }

    va_end(args);  
    return result;  
}

int main() {
    int a = 10;
    int *ptr = &a;  

    // ft_printf ile testler
    printf("== ft_printf ==\n");
    ft_printf("Char: %c\n", 'A');
    ft_printf("String: %s\n", "Hello");
    ft_printf("Decimal: %d\n", 1);
    ft_printf("Unsigned: %u\n", 0);
    ft_printf("Hexadecimal (lowercase): %x\n", 85556);
    ft_printf("Hexadecimal (uppercase): %X\n", 85556);
    ft_printf("Pointer: %p\n", ptr); 
    ft_printf("Integer: %i\n", 1);

    // Gerçek printf ile testler
    printf("\n== Real printf ==\n");
    printf("Char: %c\n", 'A');
    printf("String: %s\n", "Hello");
    printf("Decimal: %d\n", 1);
    printf("Unsigned: %u\n", 0);
    printf("Hexadecimal (lowercase): %x\n", 85556);
    printf("Hexadecimal (uppercase): %X\n", 85556);
    printf("Pointer: %p\n", ptr);  
    printf("Integer: %i\n", 1);

    return 0;
}