/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:35:23 by tastybao          #+#    #+#             */
/*   Updated: 2023/09/25 14:46:55 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int	main(int argc, char *argv[])
{
	// Str	Str;

	if (argc != 4)
	{
		std::cout << "Please enter a filename and two strings. No more, nos less." << std::endl;
		return (1);
	}
	std::cout << argv[1];
	// Str.RegisterString(argv[2], argv[3]);
	return (0);
}
