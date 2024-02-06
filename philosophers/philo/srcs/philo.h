/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:35:45 by sgarigli          #+#    #+#             */
/*   Updated: 2024/02/06 16:39:32 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

// # define NUMBER_OF_PHILO 0
// # define TIME_TO_DIE   5000
// # define TIME_TO_EAT   300
// # define TIME_TO_SLEEP 300
// # define WAIT 1000

typedef enum e_bool
{
	FALSE,
	TRUE,
	ERROR = -1
}	t_bool;

enum e_print
{
	P_THINK,
	P_FORK,
	P_EAT,
	P_SLEEP,
	P_DEATH,
	P_FINISH
};

typedef struct s_var
{
	int				nbr_of_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				nbr_time_philo_eat;
	int				full;
	t_bool			stop;
	pthread_mutex_t	print;
	pthread_mutex_t	eat;
	pthread_mutex_t	finish;
	pthread_mutex_t	alone_fork;
}	t_var;

typedef struct s_diner
{
	t_var			*var;
	int				tag;
	pthread_t		id_philo;
	pthread_mutex_t	my_fork;
	pthread_mutex_t	look;
	t_bool			b_fork;
	long			last_meal;
	long			act_time;
	long			start_time;
	int				meal_got;
	int				ph_wait;
	int				nbr_of_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	struct s_diner	*next;
}	t_diner;

//time_utils.c
long	ft_get_time(void);
void	ft_usleep(long time);
//philo_utils.c
int		ft_atoi(const char *nptr);
void	ft_exit(t_diner **diner, t_bool status);
void	ft_mutprint(t_diner *diner, int action);
//thred_utils.c
void	ft_threadgen(t_diner **diner);
t_bool	ft_checkdeath(t_diner *diner);
void	*ft_philodeath(void *diner);
t_bool	ft_solo(t_var *var);
//input.c
t_var	*ft_var_set(int ac, char **av);
t_bool	ft_inputcheck(t_var *var);
t_diner	*ft_diner_set(t_var *var);
void	ft_thread_exec(t_diner *diner);
//error.c
t_bool	ft_malloc_err(void *ptr);
t_bool	ft_argc_err(int argc);
t_bool	ft_muterr(int info, t_diner **diner);
t_bool	ft_threrr(int info, t_diner **diner);
//list_utils.c
t_diner	*ft_dinernew(t_diner **diner, t_var *var);
void	ft_dinerclear(t_diner **lst);
void	ft_dineradd_back(t_diner **lst, t_diner *new);
void	ft_dineradd_last(t_diner **lst, t_diner *new);
t_diner	*ft_dinerlast(t_diner **diner);
//actions.c
void	*ft_think(void *arg);
void	ft_begin(t_diner **diner);
void	ft_sleep(t_diner *diner);
void	ft_eat(t_diner *diner);
void	ft_philofull(t_diner *diner);

#endif