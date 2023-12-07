#include <stdio.h>

#include "get_next_line.h"

static char *parse(char *s, char c)
{
	char *str;
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	str = (char *)malloc((ft_strlen(s) - i) + 1);
	if (!str)
		return (NULL);
	i++;
	while (s[i])
		str[j++] = s[i++];
	str[j] = '\0';
	free(s);
	return (str);
}
char *next_line(char *list)
{
	char *str;
	int i;

	i = 0;
	if(!list[i])
		return (NULL);
	while (list[i] != '\0' && list[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (list[i] && list[i] != '\n')
	{
		str[i] = list[i];
		i++;
	}
	if (list[i] == '\n')
	{
		str[i] = list[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char *create_list(char *list, int fd)
{
	char *new_list;
	int read_bytes;

	new_list = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!new_list)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(list, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, new_list, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(new_list);
			return (NULL);
		}
		new_list[read_bytes] = '\0';
		list = ft_strjoin(list, new_list);
	}
	free(new_list);
	return (list);
}

char *get_next_line(int fd)
{
	char *line;
	static char *list;
	if (fd <  0 || BUFFER_SIZE <= 0)
		return (NULL);
	list = create_list(list, fd);

	if (list)
	{
		line = next_line(list);
		list = parse(list, '\n');
		return (line);
	}
	return (NULL);
}

 int main()
{
	char *next_line;
	int fd;
	int count = 0;
	fd = open("example.txt", O_RDWR);
	if (fd < 0)
		printf("Error file");

	next_line = get_next_line(fd);
	printf("sonuc -> %s\n", next_line);
	next_line = get_next_line(fd);
	printf("sonuc -> %s\n", next_line);
	next_line = get_next_line(fd);
	printf("sonuc -> %s\n", next_line);

}
