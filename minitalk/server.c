/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: henolimp <henolimp@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/01 16:41:34 by henolimp      #+#    #+#                 */
/*   Updated: 2023/02/02 17:27:31 by henolimp      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

static void	ft_print(int c)
{
	write(1, &c, 1);
}

static void	ft_signal_handler(int signal)
{
	static int	bit = 0;
	static int	i = 0;

	if (signal == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_print(i);
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_put_str("\033[1;33m============📡============\n");
	ft_put_str("    Server running !!!\n");
	ft_put_str("        PID:");
	ft_putnbr_fd(pid, 1);
	ft_put_str("\n");
	ft_put_str("==========================\033[0m\n");
	signal(SIGUSR1, ft_signal_handler);
	signal(SIGUSR2, ft_signal_handler);
	while (1)
	{
		pause ();
	}
	return (0);
}
