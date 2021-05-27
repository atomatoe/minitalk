#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

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

void        decimal_conversion(char ascii, int power, int pid)
{
	if (power > 0)
		decimal_conversion(ascii / 2, power - 1, pid);
	if ((ascii % 2) == 1)
	{
		if(kill(pid, SIGUSR1) == -1)
		{
			ft_putstr("Error signal!\n");
			exit(0);
		}
	}
	else
	{
		if(kill(pid, SIGUSR2) == -1)
		{
			ft_putstr("Error signal!\n");
			exit(0);
		}
	}
	usleep(1000);
}

int		send_message(int server_pid, char *msg)
{
	int		i;
	int diff = 0;
	i = 0;
	while (msg[i] != '\0')
	{
		decimal_conversion(msg[i], 7, server_pid);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}

int main(int argc, char **argv)
{
    if(argc == 3)
        send_message(atoi(argv[1]), argv[2]);
    else
        ft_putstr("ERROR ARGUMENTS\n");
	return(0);
}