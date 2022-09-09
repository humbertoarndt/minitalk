/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:30:22 by harndt            #+#    #+#             */
/*   Updated: 2022/09/03 16:46:15 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * @brief Converts the message from bit to char.
 * 
 * @param str String to store the message.
 * @param c The char to convert.
 * @return char* The final message.
 */
static char	*extended_string(char *str, char c)
{
	char	*result;
	int		length;

	length = 0;
	result = NULL;
	if (str)
		length = ft_strlen(str);
	result = (char *)malloc(sizeof(char) * (length + 2));
	if (result)
	{
		result = ft_memcpy(result, str, length);
		ft_bzero(result + length, 2);
		*(result + length) = c;
	}
	if (str)
		free(str);
	return (result);
}

/**
 * @brief Handles the signal received.
 * 
 * @param signal The signal.
 */
static void	handle_sigusr(int signal)
{
	static int				bit = 0;
	static char				*string = NULL;
	static unsigned char	c = 0;

	bit++;
	c <<= 1;
	if (signal == SIGUSR2)
		c++;
	if (bit == 8)
	{
		if (c)
			string = extended_string(string, c);
		else if (string)
		{
			ft_printf("%s\n", string);
			free(string);
			string = NULL;
		}
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	t_sigaction	sa;
	sigset_t	mask;

	sigemptyset(&mask);
	sa.sa_flags = 0;
	sa.sa_mask = mask;
	sa.sa_handler = handle_sigusr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("\e[1;36mPID:\033[1;0m %d\n", getpid());
	while (TRUE)
		pause();
	return (0);
}
