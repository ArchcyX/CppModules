/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 17:19:36 by alermi            #+#    #+#             */
/*   Updated: 2026/07/09 17:21:05 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	INTERN_HPP
#define	INTERN_HPP

#include "AForm.hpp"
#include <exception>
#include <iostream>
#include <string>

class Intern {
	
	public:

		//-----------------[OCF METHODS]-----------//
		Intern();
		~Intern();
		Intern(const Intern& variant);
		Intern& operator=(const Intern& variant);
		
		//-------------------[]-------------------//
		AForm* makeForm(std::string formName, std::string target);
	
		//-----------------[EXCEPTION METHODS]----------//
		class FormNotFoundException : public std::exception
		{
			public:
				virtual	const char* what() const throw();
		};
	private:
	
};


#endif
