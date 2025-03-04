/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:12:48 by berard            #+#    #+#             */
/*   Updated: 2023/01/30 11:02:59 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = ((nb * 10) + (str[i] - 48));
		i++;
	}
	nb = nb * sign;
	return (nb);
}

int	ft_free_argv(char *argv[])
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
	return (0);
}

int	ft_normal(int argc, char *argv[], char *str, int size)
{
	int	i;
	int	bigger;
	int	nb;

	i = 1;
	bigger = 0;
	if (argc == 2)
		i = 0;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) > ft_atoi(str))
			bigger++;
		i++;
	}
	nb = size - bigger;
	return (nb);
}
