/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tastybao <tastybao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:34:37 by tastybao          #+#    #+#             */
/*   Updated: 2024/02/20 20:09:50 by tastybao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
	public :
		MutantStack(void);
		MutantStack(MutantStack const & src);
		~MutantStack(void);

		MutantStack	&operator=(MutantStack const & rhs);

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator	begin();
		iterator	end();

	private :
};

#endif
