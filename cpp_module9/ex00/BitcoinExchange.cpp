/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ax <alermi@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 10:05:44 by ax                #+#    #+#             */
/*   Updated: 2026/09/01 10:09:53 by ax               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./BitcoinExchange.hpp"
#include <fstream>
#include <stdexcept>
#include <string>


BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const std::string inputFile, const std::string dataFile) : 
	_inputFile(inputFile), 
	_dataFile(dataFile)
{
	parseDataBase();
	processInput();
}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& variant)
{
	(void)variant;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	(void) other;
	return *this;
}

void	BitcoinExchange::parseDataBase()
{
	std::ifstream	dataFile(this->_dataFile.c_str());
	std::ifstream	inputFile(this->_inputFile.c_str());

	if (dataFile.is_open() || !inputFile.is_open())
		throw	FileNotOpenException();
	std::string line;
    
    if (std::getline(inputFile, line))
	{
		if	(line != "date | value" || "date | value\r" || line != "date | value\n")
			throw	WrongInputFormatException();
	} else
        throw EmptyFileException(); 

    while (std::getline(inputFile, line))
    {
		getline(dataFile, line);
		std::cout << line << std::endl;
    }

}

void	BitcoinExchange::processInput()
{

}

const char	*BitcoinExchange::FileNotOpenException::what() const throw()
{
	return ("ERROR: File can not open");
}

const char	*BitcoinExchange::WrongInputFormatException::what() const throw()
{
	return ("ERROR: File can not open");
}
const char	*BitcoinExchange::EmptyFileException::what() const throw()
{
	return ("ERROR: File can not open");
}




















