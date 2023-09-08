/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:43:08 by tastybao          #+#    #+#             */
/*   Updated: 2023/09/08 10:33:11 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*Patricia = newZombie("Patricia");

	Patricia->announce();
	delete Patricia;
	randomChump("Jean-Michel");
	return (0);
}
