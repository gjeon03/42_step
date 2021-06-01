#include "minitalk.h"

void		activebit(int sig, siginfo_t *info, void *context)
{
	printf("11111111\n");
}

void		nullbit(int sig, siginfo_t *info, void *context)
{
	printf("22222222\n");
}

int	main(void)
{
	char	*pid;
	struct sigaction active_act;
	struct sigaction null_act;

	active_act.sa_sigaction = activebit;
	null_act.sa_sigaction = nullbit;
	active_act.sa_flags = SA_SIGINFO;
	null_act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &active_act, NULL) != 0)
		printf("1-1-1-1-1\n");
	if (sigaction(SIGUSR2, &null_act, NULL) != 0)
		printf("2-2-2-2-2\n");
	pid = ft_itoa(getpid());
	ft_putstr_fd(pid, 1);
	write(1, "\n", 1);
	free(pid);
	while (1);
}