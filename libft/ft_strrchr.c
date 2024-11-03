/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:47:49 by yozlu             #+#    #+#             */
/*   Updated: 2024/10/29 15:51:29 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*str;

	str = (char *)s;
	len = ft_strlen(s);
	while (len >= 0)
	{
		if (str[len] == (char)c)
			return ((str + len));
		len--;
	}
	return (NULL);
}
