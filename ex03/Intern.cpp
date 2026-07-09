/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 17:21:18 by alermi            #+#    #+#             */
/*   Updated: 2026/07/09 17:24:28 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{
	std::cout << "Intern Constructor Called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor Called" << std::endl;
}

Intern::Intern(const Intern& variant)
{
	(void)variant;
}

Intern& Intern::operator=(const Intern& variant)
{
	(void)variant;
	return (*this);
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return ("Error: Form list not include this form");
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	int	lindex = -1;
	std::string	forms[3] = {
		"shrubbery creation",
        "robotomy request",
        "presidential pardon"
	};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == formName)
		{
			lindex = i;
			break;
		}
	}

	switch(lindex)
	{
		case 0:
            std::cout << "Intern creates " << formName << std::endl;
            return new ShrubberyCreationForm(target);
        case 1:
            std::cout << "Intern creates " << formName << std::endl;
            return new RobotomyRequestForm(target);
        case 2:
            std::cout << "Intern creates " << formName << std::endl;
            return new PresidentialPardonForm(target);
        default:
            std::cerr << "Error: Intern cannot create '" << formName << "' because it doesn't exist!" << std::endl;
            throw Intern::FormNotFoundException();
    }
}
