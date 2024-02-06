/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:05:07 by sgarigli          #+#    #+#             */
/*   Updated: 2024/01/16 15:40:00 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_signal_err(void)
{
	write (2, "Error: unexpected signal behavior\n", 34);
	exit(1);
}

static void	ft_action(int sig)
{
	static int	bit_count = 0;

	if (sig == SIGUSR2)
	{
		ft_printf("<client [%d]: sent %d byte>\n", getpid(), ++bit_count);
		exit (0);
	}
	else if (sig == SIGUSR1)
		++bit_count;
}

void	ft_send_character(int pid, unsigned char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 128)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_signal_err();
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_signal_err();
		}
		c <<= 1;
		i++;
		pause();
		usleep(100);
	}
}

void	ft_send_message(int pid, char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		ft_send_character(pid, message[i]);
		i++;
	}
	ft_send_character(pid, '\0');
}

int	main(int argc, char **argv)
{
	int	ser_pid;

	if (argc != 3)
	{
		write (2, "Error: wrong input\n", 19);
		return (-1);
	}
	signal(SIGUSR1, ft_action);
	signal(SIGUSR2, ft_action);
	ser_pid = ft_atoi(argv[1]);
	if (ser_pid <= 0)
	{
		write (2, "Error: wrong pid\n", 17);
		return (-1);
	}
	ft_send_message(ser_pid, argv[2]);
	return (0);
}
