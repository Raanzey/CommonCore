/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:18:07 by yozlu             #+#    #+#             */
/*   Updated: 2024/10/28 13:04:46 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*dst;
	unsigned char	*src;

	dst = (unsigned char *)s1;
	src = (unsigned char *)s2;
	while (n-- && (*dst || *src))
	{
		if (*dst != *src)
			return (*dst - *src);
		dst++;
		src++;
	}
	return (0);
}
