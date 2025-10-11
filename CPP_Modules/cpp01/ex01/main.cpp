/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 03:31:36 by alermi            #+#    #+#             */
/*   Updated: 2025/10/11 04:24:59 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <sstream>

int main(void)
{
	int		N;
	Zombie	*zombies;
	
	std::ostringstream oss;

	N = 5;
    std::cout << "Start the sim" << std::endl;
	zombies = zombieHorde(N, "Zombiefirst");
	for(int	i = 0; i < N; i++)
	{
		oss.str("");
		oss.clear();
		oss << "Zombie" << i + 1;
		zombies[i].setName(oss.str());
		zombies[i].announce();
	}
	delete [] zombies;
	std::cout << "End the sim" << std::endl;
	return (0);
}
