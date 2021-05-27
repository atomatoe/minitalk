/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 07:28:00 by atomatoe          #+#    #+#             */
/*   Updated: 2021/05/27 07:49:24 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	ft_putstr(char *str);
void	error(char *str);
void	decimal_conversion(char ascii, int power, int pid);
int		send_message(int server_pid, char *msg);
void	my_handler(int signum, siginfo_t *siginfo, void *unused);

#endif