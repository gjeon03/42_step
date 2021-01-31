/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 21:40:53 by gjeon             #+#    #+#             */
/*   Updated: 2021/01/31 20:38:20 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	new_line_find(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	output_line(char **str, char **line, int i, char *buf)
{
	size_t	len;
	char	*temp;

	free(buf);
	(*str)[i] = '\0';
	*line = ft_strdup(*str);
	len = ft_strlen(*str + i + 1);
	if (len == 0)
	{
		free(*str);
		*str = 0;
		return (1);
	}
	temp = ft_strdup(*str + i + 1);
	free(*str);
	*str = temp;
	return (1);
}

int	read_remainder(char **str, char **line, char *buf)
{
	if (*str && new_line_find(*str) >= 0)
		return (output_line(str, line, new_line_find(*str), buf));
	else if (*str)
	{
		*line = *str;
		*str = 0;
		free(buf);
		return (0);
	}
	free(buf);
	*line = ft_strdup("");
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	int			newline_location;
	ssize_t		read_size;
	static char	*back_up[O_MAX];

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		back_up[fd] = ft_strjoin(back_up[fd], buf);
		newline_location = new_line_find(back_up[fd]);
		if (newline_location >= 0)
			return (output_line(&back_up[fd], line, newline_location, buf));
	}
	if (read_size < 0)
		return (-1);
	return (read_remainder(&back_up[fd], line, buf));
}
