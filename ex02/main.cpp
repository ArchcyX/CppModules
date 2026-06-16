/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 09:35:51 by alermi            #+#    #+#             */
/*   Updated: 2026/06/07 09:35:52 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <exception>
#include <cstdlib>

void	customTerminate()
{
	std::cout << "abort yiyor aslında sistem" << std::endl;
	exit(1);
}

int	main(void)
{
	std::cout << "\n\n------------------ PROCESS INITILIZED ----------------\n\n" << std::endl;
	std::cout << "initilize a big name" << std::endl;

	std::set_terminate(customTerminate);
	
	std::cout << "initilize Error exception Constructor" << std::endl;
	Bureaucrat	gavernorError("sajdşsadlas", 200);
	std::cout << "ne alaka" << std::endl;
	Bureaucrat	gavernor2("Deneme", 100);
	std::cout << "Success Governor Constructor Called" << std::endl; 
	return (0);
}
