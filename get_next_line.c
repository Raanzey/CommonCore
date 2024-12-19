/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:25:36 by yozlu             #+#    #+#             */
/*   Updated: 2024/12/19 17:28:01 by yozlu            ###   ########.fr       */
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
		return (NULL);
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
	if (!station[i])
		return (free(station), NULL);
	temp = ft_strchr(station, '\n');
	if (temp)
	{
		after_station = ft_substr(temp, 1, ft_strlen(temp));
		if (!after_station)
		{
			free(station);
			return (NULL);
		}
		free(station);
		return (after_station);
	}
	temp = ft_strchr(station, '\0');
	after_station = ft_substr(temp, 0, ft_strlen(temp));
	if (!after_station)
		return (free(station), NULL);
	return (free(station), after_station);
}

char	*station_read(char *buffer, char *station, int fd)
{
	int	count;

	count = 1;
	while (!ft_strchr(station, '\n') && count != 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
		{
			free(buffer);
			if (station)
			{
				free(station);
				station = NULL;
			}
			return (NULL);
		}
		buffer[count] = '\0';
		station = ft_strjoin(station, buffer);
	}
	return (station);
}

char	*get_next_line(int fd)
{
	static char	*station;
	char		*result;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (free(buffer), NULL);
	station = station_read(buffer, station, fd);
	if (!station)
		return (NULL);
	free(buffer);
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
