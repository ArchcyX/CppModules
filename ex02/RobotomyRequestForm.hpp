/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 13:55:03 by alermi            #+#    #+#             */
/*   Updated: 2026/06/07 17:25:02 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"
#include <iostream>

class	RobotomyRequestForm : public AForm
{
	public:
		//--------------------------
		//				 OCF METHODS
		//--------------------------
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& variant);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	private:
		std::string	_target;
	
	protected:
		virtual	void	executionAction() const;
};

