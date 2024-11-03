/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:18:14 by yozlu             #+#    #+#             */
/*   Updated: 2024/10/28 13:00:15 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)ptr;
	while (n--)
	{
		if (*p != (unsigned char)c)
			p++;
		else
			return (p);
	}
	return (NULL);
}
