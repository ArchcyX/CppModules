/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 16:50:38 by alermi            #+#    #+#             */
/*   Updated: 2026/07/13 13:20:40 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScalarConvertor.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <limits>

ScalarConvertor::ScalarConvertor()
{

}

ScalarConvertor::~ScalarConvertor()
{

}

ScalarConvertor::ScalarConvertor(const ScalarConvertor& variant)
{
	(void)variant;
}

ScalarConvertor& ScalarConvertor::operator=(const ScalarConvertor& other)
{
	(void)other;
	return *this;
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
    return (digit_flag);
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

void	ScalarConvertor::printChar(const std::string& value)
{
	char c = value[0];

	int		i = static_cast<int>(c);
	float	f = static_cast<float>(c);
	double	d = static_cast<double>(c);

	if (std::isprint(c))
        std::cout << "char: '" << c << "'\n";
    else
        std::cout << "char: Non displayable\n";

    std::cout << "int: " << i << "\n";

    std::cout << "float: " << f << ".0f\n";
    std::cout << "double: " << d << ".0\n";
}

void ScalarConvertor::printInt(const std::string& value)
{
    char* endPtr;
    long asLong = std::strtol(value.c_str(), &endPtr, 10);

    if (asLong > std::numeric_limits<int>::max() || asLong < std::numeric_limits<int>::min())
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }

    int asInt = static_cast<int>(asLong);

    // Char
    if (asInt < 0 || asInt > 127)
        std::cout << "char: impossible\n";
    else if (!std::isprint(asInt))
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << static_cast<char>(asInt) << "'\n";

    std::cout << "int: " << asInt << "\n";
    std::cout << "float: " << static_cast<float>(asInt) << ".0f\n";
    std::cout << "double: " << static_cast<double>(asInt) << ".0\n";
}

void ScalarConvertor::printFloatAndDouble(const std::string& value)
{
    char* endPtr;
    double asDouble = std::strtod(value.c_str(), &endPtr);
    float asFloat = static_cast<float>(asDouble);

    if (asDouble < 0 || asDouble > 127)
        std::cout << "char: impossible\n";
    else if (!std::isprint(static_cast<int>(asDouble)))
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << static_cast<char>(asDouble) << "'\n";

    if (asDouble > std::numeric_limits<int>::max() || asDouble < std::numeric_limits<int>::min())
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(asDouble) << "\n";

    if (asFloat == static_cast<int>(asFloat))
	{
        std::cout << "float: " << asFloat << ".0f\n";
        std::cout << "double: " << asDouble << ".0\n";
    }
	else 
	{
        std::cout << "float: " << asFloat << "f\n";
        std::cout << "double: " << asDouble << "\n";
    }
}

void ScalarConvertor::printPseudoLiteral(const std::string& literal) 
{
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";

    if (literal == "nan" || literal == "nanf")
	{
        std::cout << "float: nanf\n";
        std::cout << "double: nan\n";
    }
	else if (literal == "+inf" || literal == "+inff")
	{
        std::cout << "float: +inff\n";
        std::cout << "double: +inf\n";
    }
	else if (literal == "-inf" || literal == "-inff")
	{
        std::cout << "float: -inff\n";
        std::cout << "double: -inf\n";
    }
}

void ScalarConvertor::convert(const std::string& literal) 
{
    if (isPseudoLiteral(literal))
        printPseudoLiteral(literal);
    else if (isChar(literal))
        printChar(literal);
    else if (isInt(literal))
        printInt(literal);
    else if (isFloat(literal) || isDouble(literal))
        printFloatAndDouble(literal);
    else
	{
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
    }
}
