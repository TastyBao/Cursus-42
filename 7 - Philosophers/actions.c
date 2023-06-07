/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tastybao <tastybao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:25:01 by berard            #+#    #+#             */
/*   Updated: 2023/06/07 12:17:33 by tastybao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* Set up the loop of actions that the philosopher will undertake. */
void	*actions(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->id % 2 == 0)
		usleep(3000);
	philo->last_meal = get_timestamp();
	while (philo->alive)
	{
		dead_or_alive(philo);
		think(philo);
		eat(philo);
		sleepy(philo);
	}
	return (NULL);
}

/* Check whether the philosopher is already dead or whether he is due to die. */
void	dead_or_alive(t_philo *philo)
{
	if (!philo->alive)
		return ;
	if (philo->last_meal + philo->t_die < get_timestamp())
	{
		philo->alive = false;
		display_logs(philo, DEAD);
	}
}

/* Loop as long as it is alive and has not waited the required time. */
void	sleepy(t_philo *philo)
{
	int	asleep;

	if (!philo->alive)
		return ;
	asleep = get_timestamp();
	display_logs(philo, SLEEP);
	if (philo->alive && asleep + philo->t_sleep < get_timestamp())
		dead_or_alive(philo);
}

void	think(t_philo *philo)
{
	if (!philo->alive)
		return ;
	display_logs(philo, THINK);
	philo->hand = 0;
	while (philo->alive && philo->hand != 2)
	{
		if (grab_fork(philo, &philo->forks[philo->id - 1]))
			philo->hand++;
		if (grab_fork(philo, &philo->forks[(philo->id % philo->nb_philos)]))
			philo->hand++;
		dead_or_alive(philo);
	}
}

void	eat(t_philo *philo)
{
	int	ultima_cena;

	if (!philo->alive)
		return ;
	display_logs(philo, EAT);
	ultima_cena = get_timestamp();
	philo->last_meal = get_timestamp();
	while (philo->alive && ultima_cena + philo->t_eat > get_timestamp())
		dead_or_alive(philo);
	if (philo->alive)
	{
		philo->meal++;
		if (philo->meal == philo->n_meal)
		{
			; // Manager
		}
	}
	free_fork(&philo->forks[philo->id - 1]);
	free_fork(&philo->forks[(philo->id % philo->nb_philos)]);
}

