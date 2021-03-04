#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*tmp;
	int		len;

	len = ft_strlen(str);
	if (!(tmp = malloc(sizeof(char) * (len + 1))))
		return (0);
	tmp[len] = 0;
	while (--len >= 0)
		tmp[len] = str[len];
	return (tmp);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tmp;
	int		s1_len;
	int		s2_len;
	int		i;
	int		j;

	if (s1 == 0 && s2 == 0)
		return (0);
	i = 0;
	j = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(tmp = malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (0);
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	while (s2[j])
		tmp[i++] = s2[j++];
	tmp[i] = 0;
	return (tmp);
}

int		nl_find(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		output_line(char **back, char **line, char *buf, int nl)
{
	int		len;
	char	*tmp;

	free(buf);
	(*back)[nl] = 0;
	*line = ft_strdup(*back);
	len = ft_strlen(*back + nl + 1);
	if (len == 0)
	{
		free(*back);
		*back = 0;
		return (1);
	}
	tmp = ft_strdup(*back + nl + 1);
	free(*back);
	*back = tmp;
	return (1);
}

int		line_remainder(char **back, char **line, char *buf)
{
	if (nl_find(*back) >= 0)
		return (output_line(back, line, buf, nl_find(*back)));
	else if (*back)
	{
		*line = *back;
		*back = 0;
		free(buf);
		return (0);
	}
	free(buf);
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(char **line)
{
	char		*buf;
	static char	*back;
	char		*tmp;
	int			read_size;

	if (line == 0)
		return (-1);
	if (!(buf = malloc(sizeof(char) * 101)))
		return (-1);
	if (back == 0)
		back = ft_strdup("");
	while ((read_size = read(0, buf, 100)) > 0)
	{
		buf[read_size] = 0;
		tmp = ft_strjoin(back, buf);
		free(back);
		back = tmp;
		if (nl_find(back) >= 0)
			return (output_line(&back, line, buf, nl_find(back)));
	}
	if (read_size < 0)
		return (-1);
	return (line_remainder(&back, line, buf));
}
