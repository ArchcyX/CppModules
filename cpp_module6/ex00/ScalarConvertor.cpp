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

//==============================================================================
//															CONVERTION METHODS
//==============================================================================

bool	ScalarConvertor::isInt(const std::string& value)
{
	size_t	i = 0;

	if (value.empty())
		return (false);

	if (value[i] == '-' || value [i] == '+')
	{
		i++;
		if (value.length() == i)
			return (false);
	}

	for (; i < value.length(); i++)
	{
		if (!std::isdigit(value[i]))
			return (false);
	}
	return (true);
}

bool	ScalarConvertor::isFloat(const std::string& value)
{
	int	dot_flag = 0;

	if (value.empty() || (value.length()) - 1 != 'f')
		return (false);

	for (int i = 0; (value.length()) - 1; i++)
	{
		if (std::isdigit(value[i]))
			continue;
		else if (value[i] == '.' && dot_flag == 0)
			dot_flag = 1;
		else if (value[i] == '.' && dot_flag == 1)
			return (false);
	}
}

bool	ScalarConvertor::isChar(const std::string& value)
{
	if (value.length() != 1 || (std::isdigit(value[0])))
		return (false);
	return (true);
}

bool	ScalarConvertor::isDouble(const std::string& value)
{

}

bool	ScalarConvertor::isPseudoLiteral(const std::string& value)
{
	return (value == "-inf" || value == "-inf" || value == "nanf" || value == "-inff" ||
			value == "nan" || value == "+inf");
}


