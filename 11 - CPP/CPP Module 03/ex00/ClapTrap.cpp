/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tastybao <tastybao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:17:36 by tastybao          #+#    #+#             */
/*   Updated: 2023/10/07 19:24:59 by tastybao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("ClapTrap"), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "A new ClapTrap is created. It is.... " << _name << "!" << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "A new ClapTrap is created. It is.... " << _name << "!" << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_name = rhs._name;
	_HitPoints = rhs._HitPoints;
	_EnergyPoints = rhs._EnergyPoints;
	_AttackDamage = rhs._AttackDamage;

	return *this;
}

void	ClapTrap::attack(const std::string &target)
{
	if (_HitPoints == 0)
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
	else if (_EnergyPoints == 0)
		std::cout << "ClapTrap " << _name << " is out of energy." << std::endl;
	else
	{
		_EnergyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target;
		std::cout << " causing " << _AttackDamage << " points of damage!" << std::endl;
	}
	return;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_HitPoints == 0)
		std::cout << "ClapTrap " << _name << " is already on the ground. Don't attack a dead body!" << std::endl;
	else
	{
		if (_HitPoints <= amount)
		{
			std::cout << "ClapTrap " << _name << " is attacked and takes " << amount << " damage. He is dead!" << std::endl;
			_HitPoints = 0;
		}
		else
		{
			std::cout << "ClapTrap " << _name << " is attacked and takes " << amount << " damage. He is still alive!" << std::endl;
			_HitPoints -= amount;
		}
	}
	return;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_EnergyPoints > 0 && _HitPoints > 0)
	{
		_EnergyPoints--;
		if (amount + _HitPoints >= 10)
		{
			_HitPoints = 10;
			std::cout << "ClapTrap " << _name << " is now full life!" << std::endl;
		}
		else
		{
			_HitPoints += amount;
			std::cout << "ClapTrap " << _name << " is restored to " << amount << " hit points!" << std::endl;
		}
	}
	else
		std::cout << "ClapTrap " << _name << " is unable to repair itself..." << std::endl;
	return;
}

void	ClapTrap::getStatus(void) const
{
	std::cout << "ClapTrap " << _name << " has " << _HitPoints << " hit points and " << _EnergyPoints << " energy points left." << std::endl;
	std::cout << "Its attack points are " << _AttackDamage << "." << std::endl;
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return _HitPoints;
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return _AttackDamage;
}

void	ClapTrap::setAttackDamage(unsigned int power)
{
	_AttackDamage = 1 * power;
	return;
}
