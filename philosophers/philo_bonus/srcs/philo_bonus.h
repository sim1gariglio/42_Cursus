/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarigli <sgarigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:34:53 by sgarigli          #+#    #+#             */
/*   Updated: 2024/02/06 16:40:10 by sgarigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <semaphore.h>

typedef struct s_data	t_data;
typedef struct s_diner	t_diner;

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
}	t_var;

typedef struct s_diner
{
	int			tag;
	pid_t		pid;
	int			status;
	pid_t		finished_pid;
	t_data		*data;
	int			mealgot;
	long		lastmeal;
	long		starttime;
	pthread_t	undertaker;
	pthread_t	philokill;
	pthread_t	amifull;
	t_var		var;
	t_bool		imdead;
}	t_diner;

typedef struct s_data
{
	t_diner		*diner;
	sem_t		*chopstick;
	sem_t		*print;
	sem_t		*full;
	sem_t		*death;
	sem_t		*semafero;
	sem_t		*dieall;
	sem_t		*meal;
	long		starttime;
	int			total_meal;
	t_var		var;
	t_bool		b_death;
	int			i_full;
	pthread_t	ciccio;
}	t_data;

//time_utils_bonus.c
long	ft_get_time(void);
void	ft_usleep(long time);
//philo_utils_bonus.c
t_bool	ft_malloc_err2(void *ptr, t_data *data);
int		ft_atoi(const char *nptr);
void	ft_semprint(t_diner *diner, t_data *data, int action);
void	ft_unlink(void);
//input_bonus.c
void	ft_philo_init(t_diner *diner, t_data *data, int i);
t_var	ft_var_set(int ac, char **av);
t_bool	ft_inputcheck(t_var var, t_data *data);
t_data	*ft_datagen(int ac, char **av);
void	ft_philo_gen(t_data *data);
//error_bonus.c
t_bool	ft_malloc_err(void *ptr);
t_bool	ft_argc_err(int argc);
void	ft_sem_err(t_data *data);
t_bool	ft_threrr(int info, t_data *data);
void	ft_fork_err(t_data *data, t_diner *diner);
//philo_end_bonus.c
void	ft_wait(t_data *data);
void	ft_freedata(t_data *data);
void	ft_exit(t_data *data);
//actions_bonus.c
void	ft_think(t_data *data, t_diner *diner);
void	ft_eat(t_data *data, t_diner *diner);
void	ft_sleep(t_data *data, t_diner *diner);
void	ft_solo(t_data *data, t_diner *diner);
//threads_bonus.c
void	*ft_checkdeath(void *arg);
void	*ft_philodied(void *arg);
void	*ft_philofull(void *arg);

#endif