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

class	Form;

class Bureaucrat
{
    public:
        // -------------------------------------------------------
        // Exceptions
        // -------------------------------------------------------
        class GradeTooHighException : public std::exception
		{
            public:
				GradeTooHighException(const std::string& errorName);
                virtual const char* what() const throw();
        	private:
				std::string	_errorName;
		};
        
        class GradeTooLowException : public std::exception
		{
            public:
				GradeTooLowException(const std::string& errorName);
                virtual const char* what() const throw();
        	private:
				std::string	_errorName;
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
		void	signForm(Form& form);

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
