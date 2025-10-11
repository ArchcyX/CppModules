/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 03:35:41 by alermi            #+#    #+#             */
/*   Updated: 2025/10/11 04:12:42 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string zombie_name)
{
    name = zombie_name;   
}

Zombie::~Zombie ()
{
    std::cout << "Destructor Called!" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->name << ":Brainnzzzz" << std::endl; 
}

void    Zombie::setName(const std::string& horde_name)
{
    name = horde_name;
}