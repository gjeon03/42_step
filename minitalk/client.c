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

int		send_char(int pid, char ch, int i)
{
	uint8_t	bit;

	bit = 1 << 6;
	while (bit)
	{
		if (ch & bit)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_putstr_fd("ERROR\nInvalid pid.\n", 1);
				return (-1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_putstr_fd("ERROR\nInvalid pid.\n", 1);
				return (-1);
			}
		}
		bit >>= 1;
		usleep(70);
	}
	return (++i);
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
			while (av[2][i] && i >= 0)
				i = send_char(pid, av[2][i], i);
			if (i >= 0)
				send_char(pid, av[2][i], i);
		}
		else
			ft_putstr_fd("ERROR\nEnter the pid as an integer.\n", 1);
	}
	else
		ft_putstr_fd("ERROR\nThe argument is incorrect.\n", 1);
	return (0);
}
