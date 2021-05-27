/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 07:27:32 by atomatoe          #+#    #+#             */
/*   Updated: 2021/05/27 07:28:10 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	ft_putstr(char *str);
void	error(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	sig_to_str(int bin);
void	my_handler(int signum, siginfo_t *siginfo, void *unused);

#endif