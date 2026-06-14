/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 13:55:12 by alermi            #+#    #+#             */
/*   Updated: 2026/06/07 17:28:09 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>

class	ShrubberyCreationForm : public AForm
{
	public:
		//----------------------------------
		//                       OCF METHODS
		//----------------------------------
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& variant);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	private:
		std::string	_target;
	
	protected:
		virtual void	executionAction() const;
};

#endif
