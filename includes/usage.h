/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 22:19:41 by harndt            #+#    #+#             */
/*   Updated: 2022/08/31 20:18:58 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USAGE_H
# define USAGE_H

# define USG "\033[1;32mUsage:\033[1;0m ./client <PID> <MESSAGE>		\
			\n\033[1;32m->\033[1;0m <PID>\t Server PID					\
			\n\033[1;32m->\033[1;0m <MESSAGE>\t Message to be sent to Server"
# define ZER "\033[1;32mUsage:\033[1;0m <PID> can't be 0"
# define ERR "\033[1;32mERROR\033[1;0m while trying to send signal"
#endif
