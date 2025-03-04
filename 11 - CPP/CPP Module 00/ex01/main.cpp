/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:14:01 by tastybao          #+#    #+#             */
/*   Updated: 2023/09/05 16:02:03 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	std::string	input;
	PhoneBook	PhoneBook;

	while (1)
	{
		std::cout << "Please enter a command ; ";
		std::getline(std::cin, input);
		if (input == "ADD")
			PhoneBook.AddContact();
		else if (input == "SEARCH")
			PhoneBook.SearchContact();
		else if (input == "EXIT" || std::cin.eof())
			break;
		else
			std::cout << "Please enter a valid command (ADD, SEARCH, EXIT)" << std::endl;
	}
	return (0);
}
