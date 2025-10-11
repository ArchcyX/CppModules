/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 02:25:06 by alermi            #+#    #+#             */
/*   Updated: 2025/10/11 02:50:22 by alermi           ###   ########.fr       */
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