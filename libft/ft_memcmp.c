/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:30:25 by yozlu             #+#    #+#             */
/*   Updated: 2024/10/17 19:23:26 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*dst;
	unsigned char	*src;

	dst = (unsigned char *)s1;
	src = (unsigned char *)s2;
	while (n-- && (dst || src))
	{
		if (*dst != *src)
			return (*dst - *src);
		dst++;
		src++;
	}
	return (0);
}
