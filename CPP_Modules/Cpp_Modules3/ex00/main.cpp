/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 20:57:50 by alermi            #+#    #+#             */
/*   Updated: 2026/01/12 20:23:00 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << "\n=== Basic Functionality Tests ===" << std::endl;
	ClapTrap	robot1("R2D2");
	ClapTrap	robot2("C3PO");

	robot1.attack("Enemy");
	robot1.takeDamage(5);
	robot1.beRepaired(3);

	robot2.attack("Target");
	robot2.takeDamage(10);
	robot2.attack("Enemy");

	std::cout << "\n=== Energy Depletion Test ===" << std::endl;
	ClapTrap	energyTest("EnergyBot");
	for (int i = 0; i < 12; i++)
	{
		std::cout << "Action " << i + 1 << ": ";
		energyTest.attack("Target");
	}

	std::cout << "\n=== Death Scenario Test ===" << std::endl;
	ClapTrap	deathTest("DeathBot");
	deathTest.takeDamage(10);
	deathTest.attack("Target");
	deathTest.beRepaired(5);

	std::cout << "\n=== Copy Constructor Test ===" << std::endl;
	ClapTrap	original("Original");
	ClapTrap	copy(original);
	copy.attack("Target");

	std::cout << "\n=== Assignment Operator Test ===" << std::endl;
	ClapTrap	assigned("Assigned");
	assigned = original;
	assigned.attack("Enemy");

	std::cout << "\n=== Destruction Chain ===" << std::endl;
	return (0);
}
