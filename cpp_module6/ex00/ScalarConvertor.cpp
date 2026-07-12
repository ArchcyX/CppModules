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

#include "./ScalarConvertor.hpp"
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

void	ScalarConvertor::printChar(const std::string& value)
{
	char c = literal[0];

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

void	ScalarConvertor::printInt(const std::string& value)
{
	char* endPtr;

    long asLong = std::strtol(literal.c_str(), &endPtr, 10);

    if (asLong > std::numeric_limits<int>::max()
			|| asLong < std::numeric_limits<int>::min()) {
        std::cout << "int: impossible\n";
    } else {
        int asInt = static_cast<int>(asLong);
        std::cout << "int: " << asInt << "\n";
    }
}

void	ScalarConvertor::printFloatanDouble(const std::string& value)
{
	char* endPtr;

    double asDouble = std::strtod(literal.c_str(), &endPtr);

    float asFloat = static_cast<float>(asDouble);

    std::cout << "float: " << asFloat << "f\n";
    std::cout << "double: " << asDouble << "\n";
}

static void	ScalarConvertor::convert(const std::string& literal)
{
	if (isChar(literal))
		printChar(literal);
	else if (isInt(literal))
		printInt(literal);
	else if (isDouble(literal || isFloat(literal))
		printFloatanDouble(literal);
	else if (isPseudoLiteral(literal))
		printPreudoLiteral(literal);
	else
	{
		std::cout << "char: impossible" std::endl;
		std::cout << "Int: impossible" std::endl;
		std::cout << "Float: impossible" std::endl;
		std::cout << "Double: impossible" std::endl;
	}
}
