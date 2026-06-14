/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 13:55:07 by alermi            #+#    #+#             */
/*   Updated: 2026/06/07 18:17:41 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
    std::cout << "Shrubbery Default Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "Shrubbery Parameterized Constructor Called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Shrubbery Destructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& variant) : AForm(variant), _target(variant._target)
{
    std::cout << "Shrubbery Copy Constructor Called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

void ShrubberyCreationForm::executionAction() const
{
    std::string filename = this->_target + "_shrubbery";
    std::ofstream file(filename.c_str());
    
    if (!file.is_open())
    {
        std::cerr << "Error: Could not create the file " << filename << std::endl;
        return;
    }
	file << "     0" << std::endl;
	file << "    000" << std::endl;
	file << "   00000" << std::endl;
	file << "  0000000" << std::endl;
	file << "   00000" << std::endl;
	file << "    000" << std::endl;
	file << "     0" << std::endl;
	file << "     |" << std::endl;
    file << "    _-_" << std::endl;
    
    file.close();
}
