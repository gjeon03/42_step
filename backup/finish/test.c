/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:48:40 by gjeon             #+#    #+#             */
/*   Updated: 2021/02/23 15:45:04 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int len;
	int nb = 123;
	int p_test = 1;

	printf("==========================\n");

	ft_printf("1.--c:%c:\n", '-');
	printf("1.ft_len : %d\n", len);
	ft_printf("2.--s:%.10s\n", "12345678");
	printf("2.ft_len : %d\n", len);
	ft_printf("3.--d:%2d:\n", 0);
	ft_printf("3.--d:%d:\n", 8);
	ft_printf("3.--d:%.*d:\n", 3, -12);
	ft_printf("3.--d:%1.d:\n", 123);
	
	ft_printf("123.--d:%0*d:\n", 0, 2);
	ft_printf("123.--d:%0*d:\n", -4, 2);
	ft_printf("123.--d:%0-4d:\n", 2);
	ft_printf("3.--d:%3.4d:\n", 23452);
	ft_printf("3.--d:%6.8u:\n", 23452);


	ft_printf("4.--i:%10.6i\n", nb);
	ft_printf("5.--u:%10.6u\n", nb);
	ft_printf("6.--p:%p\n", &p_test);
	ft_printf("7.--x:%10.6x\n", nb);
	ft_printf("8.--X:%10.6X\n", nb);
	
	while(1);

	/*len = printf("1.--c:%c:\n", '-');
	len = ft_printf("1.--c:%c:\n", '-');
	printf("1.ft_len : %d\n", len);
	len = ft_printf("2.--s:%.10s\n", "12345678");
	printf("2.ft_len : %d\n", len);
	len = ft_printf("3.--d:%2d:\n", 0);
	len = ft_printf("3.--d:%2d:\n", 8);
	len = ft_printf("3.--d:%.*d:\n", 3, -12);
	len = ft_printf("3.--d:%1.d:\n", 123);
	
	len = ft_printf("123.--d:%0*d:\n", 0, 2);
	len = ft_printf("123.--d:%0*d:\n", -4, 2);
	len = ft_printf("123.--d:%0-4d:\n", 2);
	len = ft_printf("3.--d:%3.4d:\n", 23452);
	len = ft_printf("3.--d:%6.8d:\n", 23452);
	
	printf("3.ft_len : %d\n", len);
	len = ft_printf("4.--i:%10.6i\n", nb);
	printf("4.ft_len : %d\n", len);
	len = ft_printf("5.--u:%10.6u\n", nb);
	printf("5.ft_len : %d\n", len);
	len = ft_printf("6.--p:%p\n", &p_test);
	printf("6.ft_len : %d\n", len);
	len = ft_printf("7.--x:%10.6x\n", nb);
	printf("7.ft_len : %d\n", len);
	len = ft_printf("8.--X:%10.6X\n", nb);
	printf("8.ft_len : %d\n", len);
	*/

	/*len = printf("1.--c:%c:\n", '-');
	printf("1.len : %d\n", len);
	len = printf("2.--s:%.10s\n", "12345678");
	printf("2.len : %d\n", len);
	len = printf("3.--d:%2d:\n", 0);
	len = printf("3.--d:%2d:\n", 8);
	len = printf("3.--d:%.*d:\n", 3, -12);
	len = printf("3.--d:%.3d:\n", -12);
	len = printf("3.--d:%-1d:\n", 123);
	len = printf("123.--d:%0*d:\n", 0, 2);
	len = printf("123.--d:%0*d:\n", -4, 2);
	len = printf("123.--d:%-4d:\n", 2);
	printf("3.len : %d\n", len);
	len = printf("4.--i:%10.6i\n", nb);
	printf("4.len : %d\n", len);
	len = printf("5.--u:%10.6u\n", nb);
	printf("5.len : %d\n", len);
	len = printf("6.--p:%20p:\n", &p_test);
	printf("6.len : %d\n", len);
	len = printf("7.--x:%10.6x\n", nb);
	printf("7.len : %d\n", len);
	len = printf("8.--X:%10.6X\n", nb);
	printf("8.len : %d\n", len);
	*/
	return (0);
}
