/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 20:47:23 by gjeon             #+#    #+#             */
/*   Updated: 2021/06/05 20:47:25 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		pid_check(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ('0' <= str[i] && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

void	send_char(int pid, uint8_t ch)
{
	uint8_t	bit;

	bit = 1 << 6;
	while (bit)
	{
		if (ch & bit)
		{
			if (kill(pid, SIGUSR1) == -1)
				print_error("ERROR\nInvalid pid.\n");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				print_error("ERROR\nInvalid pid.\n");
		}
		bit >>= 1;
		usleep(30);
	}
}

int		main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		if (pid_check(av[1]))
		{
			pid = ft_atoi(av[1]);
			while (av[2][i])
				send_char(pid, av[2][i++]);
			send_char(pid, av[2][i]);
		}
		else
			print_error("ERROR\nEnter the pid as an integer.\n");
	}
	else
		print_error("ERROR\nThe argument is incorrect.\n");
	return (0);
}
