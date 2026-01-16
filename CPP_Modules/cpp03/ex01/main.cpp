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

int	main(void)
{
	std::cout << "\n=== ClapTrap Tests ===" << std::endl;
	ClapTrap	clap("Clappy");
	clap.attack("target");
	clap.takeDamage(5);
	clap.beRepaired(3);

	std::cout << "\n=== ScavTrap Tests ===" << std::endl;
	ScavTrap	scav("Scavvy");
	scav.attack("enemy");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.guardGate();

	std::cout << "\n=== Destructor Chain ===" << std::endl;
	return (0);
}
