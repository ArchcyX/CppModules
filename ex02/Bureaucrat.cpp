/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 13:38:49 by alermi            #+#    #+#             */
/*   Updated: 2026/06/07 13:38:54 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"
#include <ostream>
#include <string>

Bureaucrat::Bureaucrat() : _name("Default Bureaucrat"), _grade(150)
{
	std::cout << "Default Constructor Called" << std::endl;
}


Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	std::cout << "\n\nBureaucrat Constructor Called\n\n" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException(this->_name);
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException(this->_name);
	else
	 	_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor Called" << std::endl;
}




Bureaucrat::Bureaucrat(const Bureaucrat& variant) : 
	_name(variant._name),
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



//-------------------------------------------------------------------------------
//					     	GRADE TOO LOW EXCEPTION OCF
//-------------------------------------------------------------------------------


Bureaucrat::GradeTooHighException::GradeTooHighException() : _personName("default person")
{
	std::cout << "Default Constructor Called" << std::endl;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
	std::cout << "Grade Too High Destructor Called" << std::endl;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string bureaucrat)
{
	std::cout << "Constructor Called" << std::endl;
	this->_personName = "Error: Bureaucrat > " + bureaucrat + "grade is TOO HIGH";
}


Bureaucrat::GradeTooHighException::GradeTooHighException(const GradeTooHighException& variant)
{
	this->_personName = variant._personName;
}

Bureaucrat::GradeTooHighException& Bureaucrat::GradeTooHighException::operator=(const GradeTooHighException& other) {
    if (this != &other)
        this->_personName = other._personName;

    return *this;
}

//-------------------------------------------------------------------------------
//					     	GRADE TOO LOW EXCEPTION OCF
//-------------------------------------------------------------------------------


Bureaucrat::GradeTooLowException::GradeTooLowException() : _personName("default")
{
	std::cout << "Default Constructor Called" << std::endl;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string bureaucrat)
{
	std::cout << "Default Constructor Called" << std::endl;
	this->_personName = "Error: Bureaucrat > " + bureaucrat + "grade is TOO LOW";
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
	std::cout << "Grade Too Low Destructor Called" << std::endl;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const GradeTooLowException& variant)
{
	this->_personName = variant._personName;
}

Bureaucrat::GradeTooLowException& Bureaucrat::GradeTooLowException::operator=(const GradeTooLowException& other)
{
    if (this != &other)
        this->_personName = other._personName;

    return *this;
}

//-------------------------------------------------------------------------------
//					     		EXCEPTION METHODS
//-------------------------------------------------------------------------------


const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return (this->_personName.c_str());
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return (this->_personName.c_str());
}


