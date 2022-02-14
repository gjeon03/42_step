/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 20:47:17 by gjeon             #+#    #+#             */
/*   Updated: 2021/06/05 20:47:18 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	put_char(int flag, int sig)
{
	static int		count;
	static uint8_t	ch;

	if (sig < 30 || 31 < sig)
		return ;
	if (flag == 1)
	{
		ch <<= 1;
		ch += 1;
	}
	else
		ch <<= 1;
	count++;
	if (count == 7)
	{
		if (ch != '\0')
			ft_putchar_fd(ch, 1);
		else
			write(1, "\n", 1);
		count = 0;
		ch = 0;
	}
}

void	activebit(int sig)
{
	put_char(1, sig);
}

void	nullbit(int sig)
{
	put_char(0, sig);
}

int		main(void)
{
	char				*pid;
	struct sigaction	active_act;
	struct sigaction	null_act;

	active_act.sa_handler = activebit;
	null_act.sa_handler = nullbit;
	if (sigaction(SIGUSR1, &active_act, NULL) != 0)
		print_error("ERROR\nThe signal was not received normally.\n");
	if (sigaction(SIGUSR2, &null_act, NULL) != 0)
		print_error("ERROR\nThe signal was not received normally.\n");
	pid = ft_itoa(getpid());
	ft_putstr_fd(pid, 1);
	write(1, "\n", 1);
	free(pid);
	while (1)
		;
	return (0);
}
