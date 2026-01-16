/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:07:40 by alermi            #+#    #+#             */
/*   Updated: 2026/01/16 15:07:40 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	std::cout << "\n=== ClapTrap Tests ===" << std::endl;
	ClapTrap	clap("Clappy");
	clap.attack("target");
	clap.takeDamage(5);
	clap.beRepaired(3);

	std::cout << "\n=== FragTrap Basic Tests ===" << std::endl;
	FragTrap	frag("Fraggy");
	frag.attack("enemy");
	frag.takeDamage(40);
	frag.beRepaired(25);
	frag.highFivesGuys();

	std::cout << "\n=== FragTrap Energy Depletion Test ===" << std::endl;
	FragTrap	energyTest("EnergyFrag");
	for (int i = 0; i < 102; i++)
	{
		if (i % 20 == 0)
			std::cout << "Action " << i + 1 << ": ";
		energyTest.attack("Target");
	}

	std::cout << "\n=== FragTrap Death Scenario Test ===" << std::endl;
	FragTrap	deathTest("DeathFrag");
	deathTest.takeDamage(100);
	deathTest.attack("Target");
	deathTest.beRepaired(10);
	deathTest.highFivesGuys();

	std::cout << "\n=== Copy Constructor Test ===" << std::endl;
	FragTrap	original("Original");
	FragTrap	copy(original);
	copy.attack("Target");
	copy.highFivesGuys();

	std::cout << "\n=== Assignment Operator Test ===" << std::endl;
	FragTrap	assigned("Assigned");
	assigned = original;
	assigned.attack("Enemy");
	assigned.highFivesGuys();

	std::cout << "\n=== Construction/Destruction Chain Test ===" << std::endl;
	{
		FragTrap	chainTest("ChainTest");
	}

	std::cout << "\n=== Destructor Chain ===" << std::endl;
	return (0);
}
