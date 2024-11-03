/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:24:14 by yozlu             #+#    #+#             */
/*   Updated: 2024/10/29 14:00:25 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_steps(long a)
{
	int	len;

	len = 0;
	if (a == 0)
		return (1);
	if (a < 0)
	{
		len++;
		a *= -1;
	}
	while (a > 0)
	{
		a /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*new;
	int		size;
	long	num;

	num = (long)n;
	size = count_steps(num);
	new = ft_calloc(size + 1, sizeof(char));
	if (new == NULL)
		return (NULL);
	if (num == 0)
		new[0] = '0';
	else if (num < 0)
	{
		new[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		new[--size] = (num % 10) + '0';
		num /= 10;
	}
	return (new);
}
