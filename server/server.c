#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n < 10)
	{
		ft_putchar(n + '0');
		return ;
	}
	ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

void sig_to_str(int bin)
{
	char	c;
	int	i;
	
	c += (bin << i++);
	if (i > 7)
	{
		if(c == '\0')
			ft_putchar('\n');
		else
			ft_putchar(c);
		c = 0;
		i = 0;
	}
}

void my_handler(int signum)
{
	static int    ascii = 0;
	static int    power = 0;

	if (signum == SIGUSR1)
		ascii += 1 << (7 - power);
	if ((power += 1) == 8)
	{
		putchar(ascii);
		power = 0;
		ascii = 0;
    }
}

int main(int argc, char **argv)
{
	if (argc != 1)
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
	signal(SIGUSR1, my_handler);
  	signal(SIGUSR2, my_handler);
	write(1, "Server started!\nPID: ", 24);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while(1)
	{
		pause();
	}
	return(0);
}