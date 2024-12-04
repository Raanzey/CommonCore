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
				result = ft_substr(result, 0, i);
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
	return (start);
}