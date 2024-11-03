/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:28:11 by yozlu             #+#    #+#             */
/*   Updated: 2024/10/16 18:48:44 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*s = src;

	if (!dst && !src)
		return (NULL);
	ptr = dst;
	while (n--)
		*ptr++ = *s++;
	return (dst);
}
