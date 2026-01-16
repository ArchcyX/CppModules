/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:07:40 by alermi            #+#    #+#             */
/*   Updated: 2026/01/16 18:21:00 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
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

void	scavSimPrinter(ScavTrap& scavbot)
{
	std::cout << "\n" << "Robot Name: " << scavbot.getName() << std::endl;
	std::cout << "Hit Points: " << scavbot.getHitpoints() << std::endl;
	std::cout << "Energy Points: " << scavbot.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage: " << scavbot.getAttackDamage() << std::endl;
	std::cout << "\n=========================================================\n" << std::endl;
}

void	fragSimPrinter(FragTrap& fragbot)
{
	std::cout << "\n" << "Robot Name: " << fragbot.getName() << std::endl;
	std::cout << "Hit Points: " << fragbot.getHitpoints() << std::endl;
	std::cout << "Energy Points: " << fragbot.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage: " << fragbot.getAttackDamage() << std::endl;
	std::cout << "\n=========================================================\n" << std::endl;
}

int	main(void)
{
	ClapTrap	clapbot("Clapbot-07");
	ScavTrap	scavbot("Scavbot-08");
	FragTrap	fragbot("Fragbot-09");

	clapOutputPrinter();
	
	std::cout << "===================[ScavTrap Simulation]==================\n" << std::endl;
	scavSimPrinter(scavbot);
	scavbot.attack("Clapbot-07");
	scavbot.takeDamage(20);
	scavbot.beRepaired(10);
	scavSimPrinter(scavbot);
	scavbot.guardGate();

	std::cout << "\n===================[FragTrap Simulation]==================\n" << std::endl;
	fragSimPrinter(fragbot);
	fragbot.attack("Scavbot-08");
	fragbot.takeDamage(30);
	fragbot.beRepaired(15);
	fragSimPrinter(fragbot);
	fragbot.highFivesGuys();

	return (0);
}
