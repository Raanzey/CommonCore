/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:25:36 by yozlu             #+#    #+#             */
/*   Updated: 2024/12/05 20:24:17 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s;

	len = ft_strlen(s1) + 1;
	s = malloc(len);
	if (s == NULL)
		return (NULL);
	return (ft_memmove(s, s1, len));
}
// char *get_line(char *result, char *start, char *station, int i, int fd)
// {
// 	read(fd, start, BUFFER_SIZE);
// 	while (result[i])
// 	{
// 		while (result[i])
// 		{
// 			if (result[i] == '\n')
// 			{
// 				i++;
// 				start = ft_substr(start, 0, i);
// 				station = result + i;
// 				start = ft_strjoin(start, result);
// 				return (start);
// 			}
// 			i++;
// 		}
// 		start = ft_strjoin(start, result);
// 		read(fd, result, BUFFER_SIZE);
// 		i = 0;
// 	}
// 	return(start);
// }
char *get_next_line(int fd)
{
	static char *station;
	char *result;
	char *start;
	int i;
	i = 0;
	result = calloc(BUFFER_SIZE, sizeof(char));
	start = calloc(BUFFER_SIZE, sizeof(char));
	if (station == NULL)
		station = calloc(BUFFER_SIZE, sizeof(char));
	read(fd, result, BUFFER_SIZE);
	while (result[i])
	{
		while (result[i])
		{
			if (result[i] == '\n')
			{
				i++;
				result = ft_substr(start, 0, i);
				station = result + i;
				start = ft_strjoin(start, result);
				return (start);
			}
			i++;
		}
		start = ft_strjoin(start, result);
		read(fd, result, BUFFER_SIZE);
		i = 0;
	}
	return (result);
}
#include <stdio.h>
int main()
{
	char *c;
	int fd = open("yusuf.txt", O_RDWR | O_CREAT, 0644);
	printf("%s", get_next_line(fd));
}
