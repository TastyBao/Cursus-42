/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:56:20 by tastybao          #+#    #+#             */
/*   Updated: 2023/09/28 13:26:58 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

#include <iostream>
#include <istream>
#include <fstream>
#include <iomanip>
#include <string>

class Str
{
	public	:
				Str();
				~Str();
				std::string	line;
				std::string	ReplaceStr(void);
				void		RegisterStr(std::string s1, std::string s2);

	private	:
				std::string	_s1;
				std::string	_s2;
};

#endif
