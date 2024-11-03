/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:47:34 by yozlu             #+#    #+#             */
/*   Updated: 2024/10/29 16:02:41 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	a;

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
