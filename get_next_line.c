/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:25:36 by yozlu             #+#    #+#             */
/*   Updated: 2024/12/07 15:58:09 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + 1;
	s = malloc(len);
	if (s == NULL)
		return (NULL);
	return (ft_memmove(s, s1, len));
}

char	*ft_strchr(const char *s, int c)
{
	char	a;

	a = (char)c;
	if (!s)
		return (NULL);
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

static char	*ft_line_before(char *station)
{
	char	*result;
	int		i;

	i = 0;
	if (!station[i])
		return (NULL);
	while (station[i] && station[i] != '\n')
		i++;
	result = malloc((i + 1 + station[i] == '\n') * sizeof(char));
	if (!result)
		return (NULL);
	result = ft_substr(station, 0, i);
	if (station[i] == '\n'){
		result[i] = station[i];	
		i++;
	}
	result[i] = '\0';
	return (result);
}

static char	*ft_line_after(char *station)
{
	int		i;
	char	*after_station;
	char	*temp;

	i = 0;
	if (!station[i])
	{
		free(station);
		return (NULL);
	}
	temp = station;
	station = ft_strchr(station, '\n') + 1;
	after_station = ft_substr(station, 0, ft_strlen(station));
	if (!after_station)
		return (NULL); // kontrol et
	free(temp);
	return (after_station);
}

char	*get_next_line(int fd)
{
	static char	*station;
	char		*result;
	char		*buffer;
	int			count;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	count = 1;
	while (!ft_strchr(station, '\n') && count != 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
			return (free(buffer), free(station), NULL);
		buffer[count] = '\0';
		station = ft_strjoin(station, buffer);
	}
	free(buffer);
	if (!station)
		return (NULL);
	result = ft_line_before(station);
	station = ft_line_after(station);
	return (result);
}
/*char *get_next_line(int fd)
{
	static char *station;//'\n'sonrası
	char *result;//kaynak
	char *start;//'\n'öncesi
	int i;
	i = 0;
	result = malloc(BUFFER_SIZE +1);
	start = malloc(BUFFER_SIZE +1);
	if (!station)
		station = malloc(BUFFER_SIZE + 1);
	read(fd, result, BUFFER_SIZE);
	while (result[i])
	{
		while (result[i])
		{
			if (result[i] == '\n')
			{

				start = ft_strjoin(start, result);
				station = ft_strchr(result, '\n');
				station++;
				return (start);
			}
			i++;
		}
		start = ft_strjoin(start, result);
		read(fd, result, BUFFER_SIZE);
		i = 0;
	}
	return (start);
}*/

/*	yusuftahafalan        an\n1
	123456789
	2131415
			*/
// #include <stdio.h>
// int main()
// {
// 	int fd = open("yusuf.txt", O_CREAT| O_RDWR);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// }
