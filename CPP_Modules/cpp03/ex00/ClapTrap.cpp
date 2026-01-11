/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 20:57:53 by alermi            #+#    #+#             */
/*   Updated: 2026/01/11 21:47:35 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{		
	std::cout << "Default Constrcutor Called" << std::endl;

	this->_name = "Default";
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Constrcutor Called" << std::endl;
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor Called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &variant)
{

}

ClapTrap ClapTrap::operator=(const ClapTrap& other)
{
	return (other);
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints == 0 || _energyPoints == 0)
	{
		std::cout << "ClapTrap" << _name << "is death or has no energy cannot attack" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << this->_name << "by attacked the" << target << _attackDamage << "point of damage" << std::endl;
}

void ClapTrap::takeDamage(unsigned int value)
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
        return;
    }
    if (value >= _hitPoints)
        _hitPoints = 0;
    else
        _hitPoints -= value;
    std::cout << "ClapTrap " << _name << " takes " << value 
              << " points of damage! HP: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int value)
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is dead and cannot repair!" << std::endl;
        return;
    }
    if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy to repair!" << std::endl;
        return;
    }
    _energyPoints--;
    _hitPoints += value;
    std::cout << "ClapTrap " << _name << " repairs itself, gaining " << value 
              << " hit points! HP: " << _hitPoints << std::endl;
}
