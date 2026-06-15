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

int	main(void)
{
	std::cout << "\n\n------------------ PROCESS INITILIZED ----------------\n\n" << std::endl;
	std::cout << "initilize a big name" << std::endl;

	std::string	hugeName(10000000, 'A');
	
	std::cout << "initilize Error exception Constructor" << std::endl;

	try 
	{
		Bureaucrat	gavernorError(hugeName, 150);
		std::cout << "Success Governor Constructor Called" << std::endl; 
	} 
	catch (const std::bad_alloc& e)
	{
		std::cerr << "Error No Memory Left on Proccess hehe:))" << std::endl;
		
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected situation " << e.what() << std::endl;
	}

	return (0);
}
