/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:07:40 by alermi            #+#    #+#             */
/*   Updated: 2026/01/16 16:05:10 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	clapbot("Clapbot-07");
	ScavTrap	scavbot("Scavbot-08");
	FragTrap	fragbot("Fragbot-09");

	clapbot.attack("Scavbot-08");
	scavbot.takeDamage(clapbot.getAttackDamage());
	scavbot.beRepaired(scavbot.getEnergyPoints() / 2);
	fragbot.highFivesGuys();
	return (0);
}
