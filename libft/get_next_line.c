/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjoie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:36:47 by chjoie            #+#    #+#             */
/*   Updated: 2022/07/25 12:43:20 by chjoie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	stopread(char *buffer)
{
	size_t	x;

	x = 0;
	while (buffer[x] != '\0')
	{
		if (buffer[x] == '\n')
			return (x);
		x++;
	}
	return (-1);
}

char	*newbuffer(char *buffer)
{
	char	*newbuffer;
	int		x;

	x = 0;
	if (ft_strlen(buffer) == 0)
	{
		free(buffer);
		return (NULL);
	}
	while (buffer[x] != '\n' && buffer[x] != '\0')
		x++;
	if (buffer[x] == '\n')
		newbuffer = ft_substr_gnl(buffer, (x + 1), ft_strlen(buffer + x + 1));
	else
		newbuffer = ft_substr_gnl(buffer, x, 1);
	free(buffer);
	return (newbuffer);
}

char	*getlign(char *bufftext)
{
	size_t	x;

	x = 0;
	while (bufftext[x] != '\0' && bufftext[x] != '\n')
		x++;
	return (ft_substr_gnl(bufftext, 0, x + 1));
}

char	*readtext(int fd, char *buffer)
{
	char	*filebuff;
	int		x;

	x = 1;
	filebuff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (filebuff == NULL)
	{
		free(buffer);
		return (NULL);
	}
	while (stopread(buffer) == -1 && x != 0)
	{
		x = read(fd, filebuff, BUFFER_SIZE);
		if (x == -1)
		{
			free(buffer);
			free(filebuff);
			return (NULL);
		}
		filebuff[x] = '\0';
		buffer = ft_strjoin_gnl(buffer, filebuff);
	}
	free(filebuff);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (text == NULL)
	{
		text = malloc(sizeof(char) * 1);
		if (text == NULL)
			return (NULL);
		text[0] = '\0';
	}
	text = readtext(fd, text);
	if (text == NULL)
		return (NULL);
	tmp = getlign(text);
	text = newbuffer(text);
	if (tmp[0] == '\0')
	{
		free(text);
		free(tmp);
		return (NULL);
	}
	return (tmp);
}
