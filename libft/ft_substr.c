/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:41:02 by yozlu             #+#    #+#             */
/*   Updated: 2024/10/29 16:09:34 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	new = ft_calloc(len + 1, sizeof(char));
	if (new == NULL)
		return (NULL);
	while (len--)
	{
		new[i] = s[start];
		i++;
		start++;
	}
	return ((char *)new);
}
