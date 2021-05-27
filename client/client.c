#include "stdio.h"
#include <unistd.h>
#include <signal.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

static	int	len(long n)
{
	int		d;

	d = 1;
	if (n < 0)
	{
		n = n * -1;
		d++;
	}
	while (n >= 10)
	{
		n = n / 10;
		d++;
	}
	return (d);
}

char		*ft_itoa(int nb)
{
	char	*str;
	int		i;
	int		f;
	long	n;

	n = nb;
	f = 0;
	i = len(n);
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	str[i] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
		f = 1;
	}
	while ((i - f) > 0)
	{
		str[i - 1] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	return (str);
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

int strlen_dec2bin(int num)
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
    return i;
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

int		charlie(int server_pid, char msg)
{
	// int bin = dec2bin(server_pid, msg);
	// // printf("%d\n", dec2bin(server_pid, msg));
	// char *str = ft_itoa(bin);
	// int i = 0;
	// printf("str = %s\n", str);
	// while(str[i])
	// {
	// 	usleep(1000);
	// 	if(str[i] == '1')
	// 	{
	// 		if (kill(server_pid, SIGUSR1) == -1)
	// 			printf("ERROR\n");
	// 		printf("Send 1\n");
	// 	}
	// 	else
	// 	{
	// 		if (kill(server_pid, SIGUSR2) == -1)
	// 			printf("ERROR\n");
	// 		printf("Send 0\n");
	// 	}
	// 	i++;
	// }

	char		c;
	
	c = 0;
	while (c < 8)
	{
		usleep(1000);
		if (((msg >> c) & 1) == 1)
		{
			if (kill(server_pid, SIGUSR1) == -1)
				printf("ERROR\n");
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				printf("ERROR\n");
		}
		c++;
	}
	return (0);
}

int		send_message(int server_pid, char *msg)
{
	int		i;
	int diff = 0;
	i = 0;
	while (msg[i] != '\0')
	{
		charlie(server_pid, msg[i]);
		i++;
	}
	charlie(server_pid, msg[i]);
	return (0);
}

int main(int argc, char **argv)
{
    if(argc == 3)
        send_message(atoi(argv[1]), argv[2]);
    else
        printf("ERROR ARGUMENTS\n");
	return(0);
}