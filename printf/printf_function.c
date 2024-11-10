/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:46:58 by yozlu             #+#    #+#             */
/*   Updated: 2024/11/10 22:23:38 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libftprintf.h"

int ft_putchar(char c)
{
	write(1, &c, 1);
	return 1;

}

int  ft_putstr(char *s)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return(ft_strlen(s));
}

int ft_putnbr(long n)
{
	long len;
	len = 0; 
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		len++;
	}
	if (n >= 10)
	{
		len += ft_putnbr(n / 10);
	}
	ft_putchar(n % 10 + '0');
	return(len + 1);
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
int ft_putnbr_hexe(unsigned long n, char x)
{
	int len;

	len = 0; 
    if (n >= 16)  
        len += ft_putnbr_hexe(n / 16, x); 
    if (x == 'X')
        write(1, &"0123456789ABCDEF"[n % 16], 1);
    else
        write(1, &"0123456789abcdef"[n % 16], 1);  
	return(len + 1);	
}
