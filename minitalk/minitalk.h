/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: henolimp <henolimp@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 11:11:25 by henolimp      #+#    #+#                 */
/*   Updated: 2023/02/02 17:25:42 by henolimp      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <limits.h>

int		ft_put_str(char *str);
int		ft_putchar(char c);
void	ft_putnbr_fd(int n, int fd);
#endif
