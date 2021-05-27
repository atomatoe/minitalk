/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 07:27:29 by atomatoe          #+#    #+#             */
/*   Updated: 2021/05/27 07:47:23 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	sig_to_str(int bin)
{
	char	c;
	int		i;

	i = 0;
	c = '\0';
	c += (bin << i++);
	if (i > 7)
	{
		if (c == '\0')
			ft_putchar('\n');
		else
			ft_putchar(c);
		c = 0;
		i = 0;
	}
}

void	my_handler(int signum, siginfo_t *siginfo, void *unused)
{
	static int	ascii = 0;
	static int	power = 0;

	(void)unused;
	if (signum == SIGUSR1)
		ascii += 1 << (7 - power);
	power += 1;
	if (power == 8)
	{
		ft_putchar(ascii);
		power = 0;
		ascii = 0;
		if (kill(siginfo->si_pid, SIGUSR2) == -1)
			error("Error signal\n");
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	catch;

	(void)argv;
	if (argc != 1)
		error("Error arguments\n");
	write(1, "Server started!\nPID: ", 21);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	catch.sa_flags = SA_SIGINFO;
	catch.sa_sigaction = my_handler;
	if ((sigaction(SIGUSR1, &catch, 0)) == -1)
		error("Error sigaction\n");
	if ((sigaction(SIGUSR2, &catch, 0)) == -1)
		error("Error sigaction\n");
	while (1)
		pause();
	return (0);
}
