/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:25:36 by yozlu             #+#    #+#             */
/*   Updated: 2024/12/14 20:00:01 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
	result = ft_substr(station, 0, i + (station[i] == '\n'));
	if (!result)
		return (free(result), NULL);
	if (station[i] == '\n')
	{
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
	temp = ft_strchr(station, '\n');
	if (temp)
	{
		after_station = ft_substr(temp, 1, ft_strlen(temp));
		if (!after_station)
		{
			free(after_station);
			return (NULL);
		}
		free(station);
		return (after_station);
	}
	if (!station[i])
		return (free(station), NULL);
	temp = ft_strchr(station, '\0');
	after_station = ft_substr(temp, 0, ft_strlen(temp));
	if (!after_station)
		return (NULL);
	return (free(station), after_station);
}
char	*station_free(char *buffer, char *station)
{
	free(buffer);
	if (station)
	{
		free(station);
		station = NULL;
	}
	return (NULL);
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
			return (station_free(buffer, station));
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

// #include <stdio.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*buf;

// 	fd = open("yusuf.txt", O_CREAT | O_RDWR);
// 	while (1)
// 	{
// 		buf = get_next_line(fd);
// 		if (buf == NULL)
// 		{
// 			free(buf);
// 			break ;
// 		}
// 		printf("%s", buf);
// 		free(buf);
// 	}
// }
