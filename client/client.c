#include "stdio.h"
#include <unistd.h>
#include <signal.h>
#include <math.h>
#include <string.h>
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

int bin2char(int n)
{
	int num;
	int dec_value;
	int base;
	int temp;
	int last_digit;
    
    num = n;
    base = 1;
    dec_value = 0;
    temp = num;
    while (temp)
    {
		last_digit = temp % 10;
		temp = temp / 10;
		dec_value += last_digit * base;
		base = base * 2;
    }
    return dec_value;
}

int dec2bin(int server_pid, int num)
{
    int bin = 0;
	int k = 1;
	int i = 0;

    while (num)
    {
        bin += (num % 2) * k;
        k *= 10;
        num /= 2;
		i++;
    }
    return bin;
}

void        decimal_conversion(char ascii, int power, int pid)
{
  if (power > 0)
    decimal_conversion(ascii / 2, power - 1, pid);
  if ((ascii % 2) == 1)
  {
	write(1, "send 1\n", 8);
    kill(pid, SIGUSR1);
  }
  else
  {
	  write(1, "send 0\n", 8);
	  kill(pid, SIGUSR2);
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