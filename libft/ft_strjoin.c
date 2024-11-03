/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:15:48 by yozlu             #+#    #+#             */
/*   Updated: 2024/10/28 13:04:24 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*size;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	size = ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (size == NULL)
		return (NULL);
	ft_memmove(size, s1, s1_len);
	ft_memmove(size + s1_len, s2, s2_len);
	size[s1_len + s2_len] = '\0';
	return (size);
}
