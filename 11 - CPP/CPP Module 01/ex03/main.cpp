/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:48:16 by berard            #+#    #+#             */
/*   Updated: 2023/09/13 14:50:17 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

int	main(void)
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	// {
	// Weapon club = Weapon("crude spiked club");
	// HumanB jim("Jim");
	// jim.setWeapon(club);
	// jim.attack();
	// club.setType("some other type of club");
	// jim.attack();
	// }
return 0;
}
