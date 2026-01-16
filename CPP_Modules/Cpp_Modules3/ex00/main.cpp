/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 20:57:50 by alermi            #+#    #+#             */
/*   Updated: 2026/01/16 17:35:05 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
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

	return (0);
}
