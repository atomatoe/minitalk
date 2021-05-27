#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

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

void my_putchar(char c)
{
	write(1, &c, 1);
}

void sig_to_str(int bin)
{
	char	c;
	int	i;
	
	c += (bin << i++);
	if (i > 7)
	{
		if(c == '\0')
			my_putchar('\n');
		else
			my_putchar(c);
		c = 0;
		i = 0;
	}
}

void my_handler(int signum)
{
	if (signum == SIGUSR1) {
        sig_to_str(1); /*write(1, "reciv 1\n", 9);*/ }
	if (signum == SIGUSR2) {
		sig_to_str(0); /*write(1, "reciv 0\n", 9);*/ }
}

void receive_signal()
{
	usleep(1000);
	if (signal(SIGUSR1, my_handler) == SIG_ERR)
		printf("Error signal!!\n");
	if (signal(SIGUSR2, my_handler) == SIG_ERR)
		printf("Error signal!!\n");
}

int main(int argc, char **argv)
{
	if (argc != 1)
	{
		printf("ERROR\n");
		return(0);
	}
	receive_signal();
	printf("Server started!\nPID: %d\n", getpid());
	while(1)
	{
		pause();
	}
	return(0);
}