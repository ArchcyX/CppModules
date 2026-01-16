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
	std::cout << "Default Constructor Called" << std::endl;

	this->_name = "Default";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Constructor Called" << std::endl;
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
	std::cout << "Copy Constructor Called" << std::endl;
	this->_name = variant._name;
	this->_hitPoints = variant._hitPoints;
	this->_energyPoints = variant._energyPoints;
	this->_attackDamage = variant._attackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints == 0 || _energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is dead or has no energy, cannot attack!" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
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

void			setName(const std::string name);
void			setHitPoints(const unsigned int hitPoints);
void			setEnergyPoints(const unsigned int energyPoints);
void			SetAttackDamage(const unsigned int attackDamage);

std::string		ClapTrap::getName() const { return (this->_name);};

unsigned int	ClassTrap::getHitpoints() const {return (this->_hitPoints);};
unsigned int	getEnergyPoints() {};
unsigned int	getAttackDamage() {};
