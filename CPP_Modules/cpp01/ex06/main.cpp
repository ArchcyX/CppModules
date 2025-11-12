/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 22:32:33 by alermi            #+#    #+#             */
/*   Updated: 2025/11/11 22:41:41 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

#include "Harl.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	switch (argc)
	{
		case 1:
			std::cout << "Usage: ./harlFilter <level>" << std::endl;
			return (1);
		case 2:
			break ;
		default:
			std::cout << "Too many arguments." << std::endl;
			return (1);
	}

	Harl harl_person;
	std::string level = argv[1];
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	switch (
		(level == levels[0]) * 0 +
		(level == levels[1]) * 1 +
		(level == levels[2]) * 2 +
		(level == levels[3]) * 3 +
		((level != levels[0]) && (level != levels[1]) && (level != levels[2]) && (level != levels[3])) * -1
	)
	{
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			harl_person.complain("DEBUG");
			std::cout << std::endl;
			// fall through
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			harl_person.complain("INFO");
			std::cout << std::endl;
			// fall through
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			harl_person.complain("WARNING");
			std::cout << std::endl;
			// fall through
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			harl_person.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}

	return (0);
}

