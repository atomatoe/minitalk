// by atomatoe

#ifndef SERVER_H
# define SERVER_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	ft_putstr(char *str);
void	error(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	sig_to_str(int bin);
void	my_handler(int signum, siginfo_t *siginfo, void *unused);

#endif