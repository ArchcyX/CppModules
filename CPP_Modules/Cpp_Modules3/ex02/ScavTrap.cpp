/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 20:27:52 by alermi            #+#    #+#             */
/*   Updated: 2026/01/12 20:27:53 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " has been assembled!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " has been assembled!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &variant) : ClapTrap(variant)
{
	std::cout << "ScavTrap Copy Constructor Called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap Copy Assignment Operator Called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " has been disassembled!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_hitPoints == 0 || _energyPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " is dead or has no energy, cannot attack!" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << this->_name << " ferociously attacks " << target 
	          << ", dealing " << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}