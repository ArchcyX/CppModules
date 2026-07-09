/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 09:35:35 by alermi            #+#    #+#             */
/*   Updated: 2026/06/07 13:49:58 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class	AForm;

class Bureaucrat
{
    public:
        // -------------------------------------------------------
        // Exceptions
        // -------------------------------------------------------
        class GradeTooHighException : public std::exception
		{
            public:
				//------------------------------------------------
				//				  ORTHODOX CANNOCICAL FORM METHODS
				//------------------------------------------------
				GradeTooHighException();
				GradeTooHighException(const std::string bureaucrat);
				GradeTooHighException(const GradeTooHighException& variant);
				GradeTooHighException&	operator=(const GradeTooHighException& other);
				virtual ~GradeTooHighException() throw();
				//------------------------------------------------
				//								 EXCEPTION METHODS
				//------------------------------------------------
                virtual const char* what() const throw();

			private:
				std::string	_personName;
		};
        
        class GradeTooLowException : public std::exception
		{
            public:
				//------------------------------------------------
				//				  ORTHODOX CANNOCICAL FORM METHODS
				//------------------------------------------------
				GradeTooLowException();
				virtual ~GradeTooLowException() throw();
				GradeTooLowException(const std::string bureaucrat);
				GradeTooLowException(const GradeTooLowException& variant);
				GradeTooLowException& operator=(const GradeTooLowException& other);
				//------------------------------------------------
				//								 EXCEPTION METHODS
				//------------------------------------------------
				virtual const char* what() const throw();
			private:
				std::string	_personName;
		};

        // -------------------------------------------------------
        // Constructors & Destructor (OCF & Custom)
        // -------------------------------------------------------
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& variant);
        ~Bureaucrat();

        // -------------------------------------------------------
        // Operators
        // -------------------------------------------------------
        Bureaucrat& operator=(const Bureaucrat& variant);

        // -------------------------------------------------------
        // Getters (Inlined)
        // -------------------------------------------------------
        inline std::string	getName() const { return _name; }
        inline int			getGrade() const { return _grade; }

        // -------------------------------------------------------
        // Member Functions
        // -------------------------------------------------------
        void	incrementGrade();
        void	decrementGrade();
		void	signForm(AForm& form);
		void	executeForm(AForm const &form);

    private:
        // -------------------------------------------------------
        // Attributes
        // -------------------------------------------------------
        const std::string _name;
        int               _grade;
};

// =========================================================================
// Non-Member Functions (Operator Overloads)
// =========================================================================
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
