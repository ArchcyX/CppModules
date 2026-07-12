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
#include <string>
#include <cctype>

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


bool ScalarConvertor::isFloat(const std::string& value)
{
    bool    dot_flag = false;
    bool    digit_flag = false;
    size_t  i = 0;
    size_t  len = value.length();

    if (value == "-inff" || value == "+inff" || value == "nanf")
        return (true);
    if (len < 2 || value[len - 1] != 'f')
        return (false);
    if (value[i] == '-' || value[i] == '+')
        i++;
    for (; i < len - 1; i++)
    {
        if (std::isdigit(value[i])) {
            digit_flag = true;
            continue;
        }
        else if (value[i] == '.' && dot_flag == false)
            dot_flag = true;
        else if (value[i] == '.' && dot_flag == true)
            return (false);
        else
            return (false);
    }
    return (digit_flag && dot_flag);
}

bool	ScalarConvertor::isChar(const std::string& value)
{
	if (value.length() != 1 || (std::isdigit(value[0])))
		return (false);
	return (true);
}

bool ScalarConvertor::isDouble(const std::string& value)
{
    if (value == "-inf" || value == "+inf" || value == "nan")
		return (true);
    return (isFloat(value + "f"));
}

bool	ScalarConvertor::isPseudoLiteral(const std::string& value)
{
	return (value == "-inf" || value == "-inf" || value == "nanf" || value == "-inff" ||
			value == "nan" || value == "+inf");
}


