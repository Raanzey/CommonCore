/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:29:40 by yozlu             #+#    #+#             */
/*   Updated: 2024/10/30 16:31:01 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fre_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

static int	new_len(char const *s, char c)
{
	int	nlen;

	nlen = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			nlen++;
		while (*s && *s != c)
			s++;
	}
	return (nlen);
}

static char	**last_split(char **new, char const *s, char c, int len)
{
	int		i;
	int		a;

	i = 0;
	while (i < len)
	{
		while (*s == c)
			s++;
		a = 0;
		while (s[a] && s[a] != c)
			a++;
		new[i] = ft_substr(s, 0, a);
		if (!new[i])
			return (fre_tab(new), NULL);
		i++;
		s += a;
	}
	return (new);
}

char	**ft_split(char const *s, char c)
{
	int		len;
	char	**new;

	if (!s)
		return (NULL);
	len = new_len(s, c);
	new = ft_calloc((len + 1), sizeof(char *));
	if (new == NULL)
		return (NULL);
	if (!last_split(new, s, c, len))
		return (NULL);
	return (new);
}
