/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:29:39 by yozlu             #+#    #+#             */
/*   Updated: 2024/11/10 00:48:53 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

// int type_control(char c, void *x)
// {
//     if (c == 'c')
//         return(ft_putchar(*(char*)x));
//     else if (c == 's')
//         return(ft_putstr((char*)x));
//     else if (c == 'p')
//         return(ft_printf_pointer(x));   
//     else if (c == 'd')
//         return(ft_putnbr(*(long*)x));
//     else if (c == 'i')
//         return(ft_putnbr(*(long*)(x)));
//     else if (c == 'u')
//         return(ft_putnbr(*(long*)x));
//     else if (c == 'x')
//         return(ft_putnbr_hexe(*(unsigned int*)x, 'x'));
//     else if (c == 'X')
//         return(ft_putnbr_hexe(*(unsigned int*)x, 'X')); 
//     else if (c == '%')
//         return(ft_putchar('%'));
//     else
//         return 0;              
// }

// int ft_printf(const char *type, ...)
// {
//     int result;
//     int i;
//     va_list arg;
//     result = 0;
//     i = 0;
//     va_start(arg, type);
//     while (type[i])
//     {
//         if (type[i] == '%')
//         {
//            i++;
//            result += type_control(type[i], va_arg(arg, void*));  
//         }        
//         else
//         {
//             ft_putchar(type[i]);
//             result++;
//         }
//         i++;
//     }
//     va_end(arg);
//     return result;
// }

int type_control(char c, va_list args)
{
    if (c == 'c')
        return(ft_putchar(va_arg(args, int)));  // %c, int türü alır
    else if (c == 's')
        return(ft_putstr(va_arg(args, char*)));  // %s, char* türü alır
    else if (c == 'p')
        return(ft_printf_pointer(va_arg(args, void*)));  // %p, void* türü alır   
    else if (c == 'd' || c == 'i')
        return(ft_putnbr(va_arg(args, int)));  // %d ve %i, int türü alır
    else if (c == 'u')
        return(ft_putnbr(va_arg(args, unsigned int)));  // %u, unsigned int alır
    else if (c == 'x')
        return(ft_putnbr_hexe(va_arg(args, unsigned int), 'x'));  // %x, unsigned int alır
    else if (c == 'X')
        return(ft_putnbr_hexe(va_arg(args, unsigned int), 'X'));  // %X, unsigned int alır
    else if (c == '%')
        return(ft_putchar('%'));  // % karakteri
    else
        return 0;  // Geçersiz format
}

int ft_printf(const char *type, ...)
{
    int result = 0;
    int i = 0;
    va_list args;
    va_start(args, type);  // Va_list başlatılıyor

    while (type[i])  // Format stringini tarıyoruz
    {
        if (type[i] == '%')  // % gördüğümüzde, sonraki formatı işliyoruz
        {
            i++;  // %'yi geçiyoruz
            result += type_control(type[i], args);  // Format karakterine göre işlem yapıyoruz
        }        
        else  // Eğer % değilse, sadece karakteri yazdırıyoruz
        {
            ft_putchar(type[i]);
            result++;  // Yazdırılan karakteri sayıyoruz
        }
        i++;  // Sonraki karaktere geçiyoruz
    }

    va_end(args);  // Va_list'i sonlandırıyoruz
    return result;  // Toplam karakter sayısını döndürüyoruz
}

int main() {
    int *a;
    // ft_printf ile testler
    printf("== ft_printf ==\n");
    ft_printf("Char: %c\n", 'A');
    ft_printf("String: %s\n", "Hello");
    ft_printf("Decimal: %d\n", 123);
    ft_printf("Unsigned: %u\n", 123);
    ft_printf("Hexadecimal (lowercase): %x\n", 255);
    ft_printf("Hexadecimal (uppercase): %X\n", 255);
    ft_printf("Pointer: %p\n", a);
    ft_printf("Integer: %i\n", 123);

    // Gerçek printf ile testler
    printf("\n== Real printf ==\n");
    printf("Char: %c\n", 'A');
    printf("String: %s\n", "Hello");
    printf("Decimal: %d\n", 123);
    printf("Unsigned: %u\n", 123);
    printf("Hexadecimal (lowercase): %x\n", 255);
    printf("Hexadecimal (uppercase): %X\n", 255);
    printf("Pointer: %p\n", a);
    printf("Integer: %i\n", 123);

    return 0;
}