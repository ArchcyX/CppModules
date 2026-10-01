/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ax <alermi@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 20:31:59 by ax                #+#    #+#             */
/*   Updated: 2026/10/01 22:04:41 by ax               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./RPN.hpp"

RPN::RPN()
{

};

RPN::~RPN()
{

};

RPN::RPN(const RPN& variant)
{

};

RPN& RPN::operator=(const RPN& other)
{

};

bool	RPN::_isValidNumber(char c)
{

};

bool	_isOperatorChar(char c)
{

};

e_operator	RPN::_determineOperator(char c)
{

};

void		RPN::_performOperation(e_operator op)
{

};


bool	RPN::checkStack(std::stack<t_token> &stacl)
{

};

void	RPN::calculate(const std::string& expression)
{

};

const char* RPN::ErrorException::what() const throw()
{
	return ("Error");
};

