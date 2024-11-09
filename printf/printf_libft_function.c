/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_libft_function.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:41:52 by yozlu             #+#    #+#             */
/*   Updated: 2024/11/08 19:20:24 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char *ft_strchr(const char *s, int c)
{
    char a;

    a = (char)c;
    while (*s)
    {
        if (*s == (unsigned char)a)
            return ((char *)s);
        s++;
    }
    if (a == '\0')
        return ((char *)s);
    return (0);
}
size_t ft_strlen(const char *s)
{
    int a;

    a = 0;
    while (s[a] != '\0')
    {
        a++;
    }
    return (a);
}
int ft_printf_pointer(void *ptr)
{
    int len;

    len = 0; 
    write(1, "0x", 2); 
    len += 2;
    len += ft_putnbr_hexe((unsigned long)ptr, 'x'); 
    return len;
}