/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 07:51:53 by alermi            #+#    #+#             */
/*   Updated: 2025/10/11 07:52:08 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

void	HumanB::attack()
{
	if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon!" << std::endl;
}

void	HumanB::setWeapon(Weapon humanWeapon)
{
	this->weapon = &humanWeapon;
}

HumanB::HumanB(std::string humanName)
{
	std::cout << humanName << " his no weapon " << std::endl;
}
