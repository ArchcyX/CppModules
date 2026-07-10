/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 16:50:38 by alermi            #+#    #+#             */
/*   Updated: 2026/07/10 16:57:50 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvertor.hpp"

ScalarConvertor::ScalarConvertor()
{

}

ScalarConvertor::~ScalarConvertor()
{

}

ScalarConvertor::ScalarConvertor(const ScalarConvertor& variant)
{

}

ScalarConvertor& ScalarConvertor::operator=(const ScalarConvertor& other)
{

}

//
//
//

bool	ScalarConvertor::isInt(const std::string& value)
{

}

bool	ScalarConvertor::isFloat(const std::string& value)
{

}

bool	ScalarConvertor::isChar(const std::string& value)
{

}

bool	ScalarConvertor::isDouble(const std::string& value)
{

}

bool	ScalarConvertor::isPseudoLiteral(const std::string& value)
{
	return (value == "-inf" || value == "-inf" || value == "nanf" || value == "-inff" ||
			value == "nan" || value == "+inf");
}


