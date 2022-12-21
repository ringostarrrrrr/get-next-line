/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naokifuse <naokifuse@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 21:14:26 by naokifuse         #+#    #+#             */
/*   Updated: 2022/12/21 11:46:34 by naokifuse        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_about_line(int fd, char *about_line)
{
	char	*buff;
	ssize_t	read_byte;

	buff = (char *)malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!buff)
		return (NULL);
	read_byte = 1;
	while (read_byte != 0 && !ft_strchr(about_line, '\n'))
	{
		read_byte = read(fd, buff, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_byte] = '\0';
		about_line = ft_strjoin(about_line, buff);
	}
	free(buff);
	return (about_line);
}

char	*get_line(char *about_line)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!about_line[i])
		return (NULL);
	while (about_line[i] && about_line[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (about_line[i] && about_line[i] != '\n')
	{
		line[i] = about_line[i];
		i++;
	}
	if (about_line[i] == '\n')
	{
		line[i] = about_line[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_new_about_line(char *about_line)
{
	char	*new_about_line;
	char	*head_about_line;
	size_t	i;
	size_t	j;

	head_about_line = about_line;
	while (*about_line && *about_line != '\n')
		about_line++;
	if (*about_line == '\0')
	{
		free(head_about_line);
		return (NULL);
	}
	new_about_line = (char *)malloc((ft_strlen(about_line)) * sizeof(char));
	if (!new_about_line)
		return (NULL);
	i = 0;
	j = 1;
	while (about_line[j])
		new_about_line[i++] = about_line[j++];
	new_about_line[i] = '\0';
	free(head_about_line);
	return (new_about_line);
}

char	*get_next_line(int fd)
{
	static char	*about_line;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	about_line = get_about_line(fd, about_line);
	if (!about_line)
		return (NULL);
	line = get_line(about_line);
	about_line = get_new_about_line(about_line);
	return (line);
}
