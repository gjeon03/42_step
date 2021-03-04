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
	info->dot = 0;
	info->width = 0;
	info->prec = 0;
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
	int		i;

	i = ft_strlen(str);
	if (!(tmp = malloc(sizeof(char) * (i + 1))))
		return (0);
	tmp[i] = 0;
	while (--i >= 0)
		tmp[i] = str[i];
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

int		ft_putchr(char ch)
{
	write(1, &ch, 1);
	return (1);
}

int		ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
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

char	*ft_itoa(int nb)
{
	char		*tmp;
	long long	i;
	int			sign;
	int			count;

	count = 0;
	sign = nb < 0 ? -1 : 1;
	i = nb * (long long)10 * sign;
	while (i /= 10)
		count++;
	if (nb == 0 || sign < 0)
		count++;
	if (!(tmp = malloc(sizeof(char) * (count + 1))))
		return (0);
	tmp[count] = 0;
	i = nb * (long long)10 * sign;
	while (i /= 10)
		tmp[--count] = (i % 10) + '0';
	tmp[0] = sign < 0 ? '-' : tmp[0];
	tmp[0] = nb == 0 ? '0' : tmp[0];
	return (tmp);
}

char	*ft_itoa_x(unsigned int nb)
{
	char				*tmp;
	unsigned long long	i;
	int					count;
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
	{
		tmp[--count] = hex[i % 16];
	}
	tmp[0] = nb == 0 ? '0' : tmp[0];
	free(hex);
	return (tmp);
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
	else if (ft_isdigit(ch) && info->dot)
		info->prec = (info->prec * 10) + (ch - '0');
}

char	*prec_set(char *str, t_info *info)
{
	char	*prec_tmp;
	int		size;
	int		len;
	int		i;
	int		sign;

	sign = str[0] == '-' ? 1 : 0;
	len = ft_strlen(str);
	size = (info->type == 's' && info->dot) ||\
		   (info->dot && str[0] == '0' && ft_strlen(str) == 1) ||\
		   (info->prec >= len) ?\
		   info->prec + sign : len;
	if (!(prec_tmp = malloc(sizeof(char) * (size + 1))))
		return (0);
	prec_tmp[size] = 0;
	i = 0;
	if (info->type == 's' && info->dot)
	{
		while (i < size)
		{
			prec_tmp[i] = str[i];
			i++;
		}
	}
	else
	{
		ft_memset(prec_tmp, '0', size);
		while (size - len + sign + i < size)
		{
			prec_tmp[size - len + sign + i] = str[i + sign];
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
	free(width_tmp);
	free(prec_tmp);
	if (info->type != 's')
		free(str);
	return (tmp);
}

int		s_format(char *str, t_info *info)
{
	int		len;
	char	*tmp;

	if (str == 0)
		str = "(null)";
	tmp = width_prec(str, info);
	len = ft_putstr(tmp);
	return (len);
}

int		d_format(int nb, t_info *info)
{
	int		len;
	char	*tmp;

	tmp = ft_itoa(nb);
	tmp = width_prec(tmp, info);
	len = ft_putstr(tmp);
	return (len);
}

int		x_format(unsigned int nb, t_info *info)
{
	int		len;
	char	*tmp;

	tmp = ft_itoa_x(nb);
	tmp = width_prec(tmp, info);
	len = ft_putstr(tmp);
	return (len);
}

int		type_print(va_list ap, t_info *info)
{
	if (info->type == 's')
		return (s_format(va_arg(ap, char *), info));
	if (info->type == 'd')
		return (d_format(va_arg(ap, int), info));
	if (info->type == 'x')
		return (x_format(va_arg(ap, unsigned int), info));
	return (0);
}

int		ft_printf(char *str, ...)
{
	int		len;
	char	*format;
	t_info	info;
	va_list	ap;
	int		i;

	va_start(ap, str);
	i = 0;
	len = 0;
	format = (char*)str;
	while (format[i])
	{
		while (format[i] && format[i] != '%')
			len += ft_putchr(format[i++]);
		if (format[i] && format[i] == '%')
		{
			info_set(&info);
			while (format[++i] && ft_strchr(TYPE, format[i]) == 0)
				check_flags(format[i], &info);
			info.type = format[i];
			if (format[i] && ft_strchr(TYPE, format[i]))
			{
				len += type_print(ap, &info);
				i++;
			}
		}
	}
	va_end(ap);
	return (len);
}
