/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 21:36:00 by alermi            #+#    #+#             */
/*   Updated: 2026/01/12 21:36:00 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void	clapOutputPrinter(void)
{
	ClapTrap	clapbot("Clapbot-07");
	ClapTrap	testbot;

	std::cout << "\n=======[War Simulation Datas]=======\n" << std::endl;
	std::cout << "\n" << "Robot Name: " << clapbot.getName() << std::endl;
	std::cout << "Hit Points: " << clapbot.getHitpoints() << std::endl;
	std::cout << "Energy Points: " << clapbot.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage: " << clapbot.getAttackDamage() << std::endl;
	std::cout << "\n====================================\n" << std::endl;

	clapbot.attack("TestBot");
	testbot.takeDamage(10);
	testbot.beRepaired(2);

	std::cout << "\n=======[War Simulation Datas]=======\n" << std::endl;
	std::cout << "\n" << "Robot Name: " << testbot.getName() << std::endl;
	std::cout << "Hit Points: " << testbot.getHitpoints() << std::endl;
	std::cout << "Energy Points: " << testbot.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage: " << testbot.getAttackDamage() << std::endl;
	std::cout << "\n====================================\n" << std::endl;
}

void	simPrinter(ScavTrap& scavbot)
{
	std::cout << "\n" << "Robot Name: " << scavbot.getName() << std::endl;
	std::cout << "Hit Points: " << scavbot.getHitpoints() << std::endl;
	std::cout << "Energy Points: " << scavbot.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage: " << scavbot.getAttackDamage() << std::endl;
	std::cout << "\n=========================================================\n" << std::endl;
}

int	main(void)
{
	ClapTrap	clapbot("Clapbot-07");
	ScavTrap	scavbot("Scavbot-09");

	clapOutputPrinter();
	std::cout << "===================[ScavTrap Simulation]==================\n" << std::endl;
	simPrinter(scavbot);
	scavbot.attack("Clapbot-07");
	scavbot.takeDamage(20);
	scavbot.beRepaired(10);
	simPrinter(scavbot);
	scavbot.guardGate();

	return (0);
}
