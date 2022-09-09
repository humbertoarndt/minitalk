/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:29:24 by harndt            #+#    #+#             */
/*   Updated: 2022/09/01 15:31:35 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * @brief Prints a message then exits the program.
 * 
 * @param usg The message to be printed.
 */
static void	usage(char *usg)
{
	ft_printf("%s\n", usg);
	exit (EXIT_FAILURE);
}

/**
 * @brief Sends a message trough bits to the PID received.
 * 
 * @param pid The int PID where the message must be sended.
 * @param msg The String message.
 */
static void	send_message(int pid, char msg)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (kill(pid, ft_ternary(msg & (128 >> bit++), SIGUSR2, SIGUSR1)) < 0)
			usage(ERR);
		else
			usleep(INTERVAL);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*msg;

	if (argc != 3 || ft_isnum(argv[1]) == FALSE)
		usage(USG);
	pid = ft_atoi(argv[1]);
	if (pid == 0)
		usage(ZER);
	msg = argv[2];
	send_message(pid, 0);
	while (*msg)
		send_message(pid, *msg++);
	send_message(pid, 0);
	return (0);
}
