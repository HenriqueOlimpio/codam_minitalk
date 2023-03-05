/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: henolimp <henolimp@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 12:02:25 by henolimp      #+#    #+#                 */
/*   Updated: 2023/02/02 17:26:09 by henolimp      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

static int	ft_atoi(const char *str)
{
	int	i;
	int	s;
	int	n;

	i = 0;
	s = 1;
	n = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || (str[i] == '\v')
		|| str[i] == '\f' || str[i] == '\r')
			i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = s * -1;
			i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n * s);
}

static void	ft_error(void)
{
	ft_put_str("\033[0;33mError: invalid Pid or format\n");
	ft_put_str("Try something like this\n./client 00000 \"string_example\" \n\n");
	ft_put_str("You want know the correct Pid of the server?\n");
	ft_put_str("use command \n \033[0;32m top\n");
}

static void	ft_sender(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(350);
		bit++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0 || pid >= INT_MAX)
			ft_error();
		while (argv[2][i] != '\0')
		{
			ft_sender(pid, argv [2][i]);
			i++;
		}
		ft_sender(pid, '\n');
	}
	else
	{
		ft_error();
		return (1);
	}
	return (0);
}
