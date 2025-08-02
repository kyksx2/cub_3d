/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:05:30 by kjolly            #+#    #+#             */
/*   Updated: 2025/01/24 15:32:59 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*stock[1024];
	char		*line;
	char		*buffer;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (free(buffer), NULL);
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free (stock[fd]);
		free (buffer);
		stock[fd] = NULL;
		buffer = NULL;
		return (NULL);
	}
	line = line_compl(fd, stock[fd], buffer);
	free (buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	stock[fd] = set_line(line);
	return (line);
}

char	*line_compl(int fd, char *stock, char *buffer)
{
	int		r;
	char	*tmp;

	r = 1;
	while (r > 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == -1)
		{
			free(stock);
			return (NULL);
		}
		if (r == 0)
			break ;
		buffer[r] = 0;
		if (!stock)
			stock = ft_strdup("");
		tmp = stock;
		stock = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (check_newline(stock))
			break ;
	}
	return (stock);
}

int	check_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*set_line(char *line)
{
	unsigned int		i;
	char				*tmp;

	tmp = NULL;
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == 0 || line [i + 1] == 0)
		return (NULL);
	tmp = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (tmp && *tmp == 0)
	{
		free (tmp);
		tmp = NULL;
	}
	line[i + 1] = '\0';
	return (tmp);
}

/*int	main()
{
	int	fd = open("test.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);
	int fd3 = open("test3.txt", O_RDONLY);
	char *str = get_next_line(fd);
	printf("%s", str);
	char *str2 = get_next_line(fd2);
	printf("%s", str2);
	char *str3 = get_next_line(fd3);
	printf("%s", str3);
	char *str4 = get_next_line(fd);
	printf("%s\n", str4);
	char *str5 = get_next_line(fd2);
	printf("%s\n", str5);
	char *str6 = get_next_line(fd3);
	printf("%s\n", str6);
	close (fd);
	close (fd2);
	close (fd3);
	return (0);
}*/
