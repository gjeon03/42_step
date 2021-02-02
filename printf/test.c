/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:48:40 by gjeon             #+#    #+#             */
/*   Updated: 2021/02/03 00:10:24 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int		len;
	char	ch;
	char	*str = "babo";
	char	*str2 = NULL;

	ch = 'a';
	len = ft_printf("Jeon\nGyeong\nYeon\ns:%s\nc:%c\n", str, ch);
	printf("f_printf_len : %d\n", len);
	ft_printf("---c:%c--%%:%%\n", ch);
	printf("%d\n", ft_printf("c:%c---s:%s\n", ch, str2));


	len = printf("Jeon\nGyeong\nYeon\ns:%s\nc:%c\n", str, ch);
	printf("printf_len : %d\n", len);
	printf("%d\n", printf("---s:%s\n", str2));
	return (0);
}
