#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#define TYPE "dsx"

typedef struct	s_info
{
	char		type;
	int			width;
	int			prec;
	int			dot;
}				t_info;

void	info_set(t_info *info)
{
	info->width = 0;
	info->prec = 0;
	info->dot = 0;
}

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

int		ft_putchr(char ch)
{
	write(1, &ch, 1);
	return (1);
}

int		ft_putstr(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		write(1, &str[len++], 1);
	return (len);
}

int		ft_strchr(char *str, char ch)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

int		ft_isdigit(char ch)
{
	if ('0' <= ch && ch <= '9')
		return (1);
	return (0);
}

void	check_flags(char ch, t_info *info)
{
	if (ch == '.' && info->dot == 0)
		info->dot = 1;
	else if (ft_isdigit(ch) && info->dot == 0)
		info->width = (info->width * 10) + (ch - '0');
	else if (ft_isdigit(ch) && info->dot == 1)
		info->prec = (info->prec * 10) + (ch - '0');
}

void	ft_memset(char *str, char ch, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		str[i] = ch;
		i++;
	}
}

char	*ft_itoa(int nb)
{
	char		*tmp;
	int			sign;
	int			count;
	long long	i;

	sign = nb < 0 ? -1 : 1;
	i = nb * (long long)10 * sign;
	count = 0;
	while (i /= 10)
		count++;
	if (nb == 0 || sign < 1)
		count++;
	if (!(tmp = malloc(sizeof(char) * (count + 1))))
		return (0);
	tmp[count] = 0;
	i = nb * (long long)10 * sign;
	while (i /= 10)
		tmp[--count] = (i % 10) + '0';
	tmp[0] = sign == -1 ? '-' : tmp[0];
	tmp[0] = nb == 0 ? '0' : tmp[0];
	return (tmp);
}

char	*ft_itoa_x(unsigned int nb)
{
	char				*tmp;
	int					count;
	unsigned long long	i;
	char				*hex;

	count = 0;
	hex = ft_strdup("0123456789abcdef");
	i = nb * (unsigned long long)16;
	while (i /= 16)
		count++;
	if (nb == 0)
		count++;
	if (!(tmp = malloc(sizeof(char) * (count + 1))))
		return (0);
	tmp[count] = 0;
	i = nb * (unsigned long long)16;
	while (i /= 16)
		tmp[--count] = hex[i % 16];
	tmp[0] = nb == 0 ? '0' : tmp[0];
	free(hex);
	return (tmp);
}

char	*prec_set(char *str, t_info *info)
{
	char	*prec_tmp;
	int		len;
	int		total;
	int		sign;
	int		i;

	i = 0;
	len = ft_strlen(str);
	sign = str[0] == '-' ? 1 : 0;
	total = (info->type == 's' && info->dot) ||\
			(str[0] == '0' && ft_strlen(str) == 1 && info->dot) ||
			(info->prec >= len) ? info->prec + sign : len;
	if (!(prec_tmp = malloc(sizeof(char) * (total + 1))))
		return (0);
	prec_tmp[total] = 0;
	if (info->type == 's' && info->dot)
	{
		while (total > i)
		{
			prec_tmp[i] = str[i];
			i++;
		}
	}
	else
	{
		ft_memset(prec_tmp, '0', total);
		while (total - len + sign + i < total)
		{
			prec_tmp[total - len + sign + i] = str[i + sign];
			i++;
		}
		prec_tmp[0] = sign == 1 ? '-' : prec_tmp[0];
	}
	return (prec_tmp);
}

char	*width_prec(char *str, t_info *info)
{
	char	*width_tmp;
	char	*prec_tmp;
	char	*tmp;
	int		len;

	prec_tmp = prec_set(str, info);
	len = ft_strlen(prec_tmp);
	if (info->width > len)
	{
		if (!(width_tmp = malloc(sizeof(char) * (info->width - len + 1))))
			return (0);
		width_tmp[info->width - len] = 0;
		ft_memset(width_tmp, ' ', info->width - len);
	}
	else
		width_tmp = ft_strdup("");
	tmp = ft_strjoin(width_tmp, prec_tmp);
	free(prec_tmp);
	free(width_tmp);
	if (info->type != 's')
		free(str);
	return (tmp);
}

int		s_format(char *str, t_info *info)
{
	char	*tmp;
	int		len;
	
	if (str == 0)
		str = "(null)";
	tmp = width_prec(str, info);
	len = ft_putstr(tmp);
	return (len);
}

int		d_format(int nb, t_info *info)
{
	char	*tmp;
	int		len;

	tmp = ft_itoa(nb);
	tmp = width_prec(tmp, info);
	len = ft_putstr(tmp);
	return (len);
}

int		x_format(unsigned int nb, t_info *info)
{
	char	*tmp;
	int		len;

	tmp = ft_itoa_x(nb);
	tmp = width_prec(tmp, info);
	len = ft_putstr(tmp);
	return (len);
}

int		type_print(va_list ap, t_info *info)
{
	if (info->type == 's')
		return (s_format(va_arg(ap, char *), info));
	else if (info->type == 'd')
		return (d_format(va_arg(ap, int), info));
	else
		return (x_format(va_arg(ap, unsigned int), info));
}

int		ft_printf(const char *str, ...)
{
	char	*format;
	t_info	info;
	va_list	ap;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(ap, str);
	format = (char*)str;
	while (format[i])
	{
		info_set(&info);
		while (format[i] && format[i] != '%')
			len += ft_putchr(format[i++]);
		if (format[i] == '%')
		{
			while (format[++i] && ft_strchr(TYPE, format[i]) == 0)
				check_flags(format[i], &info);
			info.type = format[i];
			if (format[i] && ft_strchr(TYPE, format[i]) != 0)
			{
				len += type_print(ap, &info);
				i++;
			}
		}
	}
	va_end(ap);
	return (len);
}
