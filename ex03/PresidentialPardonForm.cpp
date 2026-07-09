/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 13:54:42 by alermi            #+#    #+#             */
/*   Updated: 2026/06/07 18:34:06 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : 
	AForm("PresidentialPardonForm", 25, 5),
	_target()
{
	std::cout << "Default Constructor Called" << std::endl;
}



PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor Called" << std::endl;
}


PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : 
	AForm("PresidentialPardonForm", 25, 5),
	_target(target)
{
	std::cout << "Constructor Called" << std::endl;
}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& variant) : 
	AForm(variant),
	_target(variant._target)
{
	std::cout << "Copy Constructor Called" << std::endl;	
}



PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}


void	PresidentialPardonForm::formExecuteAction() const
{
	std::cout << this->_target << " Pardon Form by Zaphod Beeblebrox." << std::endl;
}

