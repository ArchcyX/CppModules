/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 13:38:49 by alermi            #+#    #+#             */
/*   Updated: 2026/06/07 17:53:54 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <ostream>
#include <string>
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("Default Bureaucrat"), _grade(150)
{
	std::cout << "Default Constructor Called" << std::endl;
}


Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	std::cout << "Bureaucrat Constructor Called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
	 	_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& variant) : _name(variant._name),
													_grade(variant._grade)
{
	std::cout << "Copy Constrcutor Called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& variant)
{
	std::cout << "Operator Overload (=) Called" << std::endl;

	if (this != &variant)
		this->_grade = variant._grade;
	return (*this);
}

void	Bureaucrat::signForm(Form& form)
{
	try 
    {
        form.beSigned(*this); 
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cout << this->_name << " couldn't sign " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}
		
void	Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
	 	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
	 	_grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

