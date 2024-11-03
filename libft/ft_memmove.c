/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:35:03 by yozlu             #+#    #+#             */
/*   Updated: 2024/10/28 13:00:45 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*ptr;
	const unsigned char	*s = src;

	ptr = dst;
	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		ft_memcpy(dst, src, len);
		return (dst);
	}
	else if (dst == src)
		return (dst);
	while (len--)
		ptr[len] = s[len];
	return (dst);
}
