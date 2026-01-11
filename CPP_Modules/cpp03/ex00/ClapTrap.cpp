/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 20:57:53 by alermi            #+#    #+#             */
/*   Updated: 2026/01/11 21:33:32 by alermi           ###   ########.fr       */
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
	std::cout << this->_name << "by attacked the" << target << std::endl;
}

void	ClapTrap::takeDamage(unsigned int value)
{
	std::cout << "Take a damage" << value << ": hit points" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int value)
{
	std::cout << "Character use a repaired" << value << ": heal points";
}
