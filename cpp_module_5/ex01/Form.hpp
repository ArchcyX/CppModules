/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 09:35:45 by alermi            #+#    #+#             */
/*   Updated: 2026/06/07 11:21:04 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FORM_HPP
# define FORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class	Form
{
	public:
		//------------------------------------------------
		//EXCEPTIONS
		//------------------------------------------------
		class	GradeToHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class	GradeToLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		//------------------------------------------------
		// OCF METHODS
		// -----------------------------------------------
		Form();
		~Form();
		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		Form(const Form &variant);
		Form& operator=(const Form& variant);

		//------------------------------------------------
		// GENERAL MEMBER FUNCTION
		//------------------------------------------------
		void beSigned(const Bureaucrat& person);

		//------------------------------------------------
		// GETTER & INLINE
		//------------------------------------------------
		std::string getName() const { return (this->_name);}
		bool		getSignState() const { return (this->_isSign); }
		int			getGradeToSign() const { return (this->_gradeToSign); }
		int			getGradeToExecute() const { return (this->_gradeToExecute); }


	private:
		const std::string	_name;
		bool				_isSign;
		const int			_gradeToSign;
		const int			_gradeToExecute;
};

std::ostream&	operator<<(std::ostream& os, const Form& form);

#endif
