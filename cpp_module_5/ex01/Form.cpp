/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 09:35:40 by alermi            #+#    #+#             */
/*   Updated: 2026/06/07 13:44:40 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form() : 
				_name("Default Form"), 
				_isSign(false), 
				_gradeToSign(150), 
				_gradeToExecute(150)
{
    std::cout << "Form Default Constructor Called" << std::endl;
}

Form::~Form()
{
	std::cout << "Destructor Called" << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) :	_name(name),
																			_isSign(false),
																			_gradeToSign(gradeToSign),
																			_gradeToExecute(gradeToExecute)
{
	std::cout << "Constructor Called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeToHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeToLowException();
}

Form::Form(const Form &variant) :	_name(variant._name),
									_isSign(variant._isSign),
									_gradeToSign(variant._gradeToSign),
									_gradeToExecute(variant._gradeToExecute)
{
	std::cout << "Copy Constructor Called" << std::endl;
}

Form& Form::operator=(const Form& variant)
{
	if (this != &variant)
	{
		this->_isSign = variant._isSign;
	}
	return (*this);
}

void	Form::beSigned(const Bureaucrat& person)
{
	if (person.getGrade() > this->_gradeToSign)
		throw Form::GradeToLowException();
	this->_isSign = true;
}

const char	*Form::GradeToLowException::what() const throw()
{
	return ("Person Grade Too Low");
}

const char	*Form::GradeToHighException::what() const throw()
{
	return ("Person Grade Too High");
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "------------- Form Info -------------" << std::endl;
    os << "Form Name         : " << form.getName() << std::endl;
    os << "Sign Status       : " << (form.getSignState() ? "Signed" : "Not Signed") << std::endl;
    os << "Grade to Sign     : " << form.getGradeToSign() << std::endl;
    os << "Grade to Execute  : " << form.getGradeToExecute() << std::endl;
    os << "-------------------------------------";
    return os;
}
