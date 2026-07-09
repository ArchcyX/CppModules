/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 09:35:45 by alermi            #+#    #+#             */
/*   Updated: 2026/06/07 17:26:15 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	AFORM_HPP
# define AFORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class	AForm
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

		class	FormUnsignedException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		//------------------------------------------------
		// OCF METHODS
		// -----------------------------------------------
		AForm();
		~AForm();
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &variant);
		AForm& operator=(const AForm& variant);

		//------------------------------------------------
		// GENERAL MEMBER FUNCTION
		//------------------------------------------------
		void	beSigned(const Bureaucrat& person);
		void executionAction(const Bureaucrat& person) const;
		//------------------------------------------------
		// GETTER & INLINE
		//------------------------------------------------
		std::string getName() const { return (this->_name);}
		bool		getSignState() const { return (this->_isSign); }
		int			getGradeToSign() const { return (this->_gradeToSign); }
		int			getGradeToExecute() const { return (this->_gradeToExecute); }

		//------------------------------------------------
		//ABSTRACT INITILIZER
		//------------------------------------------------
	protected:
		virtual void	formExecuteAction() const = 0;

	private:
		const std::string	_name;
		bool				_isSign;
		const int			_gradeToSign;
		const int			_gradeToExecute;
};

std::ostream&	operator<<(std::ostream& os, const AForm& form);

#endif
