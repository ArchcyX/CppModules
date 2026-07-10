/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 16:42:58 by alermi            #+#    #+#             */
/*   Updated: 2026/06/07 17:48:19 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat
{
    public:
        // -------------------------------------------------------
        // 												Exceptions
        // -------------------------------------------------------
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        // -------------------------------------------------------
        // 				  Constructors & Destructor (OCF & Custom)
        // -------------------------------------------------------
        Bureaucrat();
        ~Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& variant);
        Bureaucrat& operator=(const Bureaucrat& variant);

        // -------------------------------------------------------
        // Getters (Inlined)
        // -------------------------------------------------------
        inline std::string getName() const { return _name; }
        inline int         getGrade() const { return _grade; }

        // -------------------------------------------------------
        // Member Functions
        // -------------------------------------------------------
        void incrementGrade();
        void decrementGrade();
		
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

#endif // BUREAUCRAT_HPP
