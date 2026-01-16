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
	ClapTrap	robot1("R2D2");
	ClapTrap	robot2("C3PO");

	robot1.attack("Enemy");
	robot1.takeDamage(5);
	robot1.beRepaired(3);

	robot2.attack("Target");
	robot2.takeDamage(10);
	robot2.attack("Enemy");

	return (0);
}
