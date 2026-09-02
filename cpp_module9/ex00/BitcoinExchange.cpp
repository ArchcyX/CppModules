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
#include <cstdio>
#include <exception>
#include <fstream>
#include <string>
#include <stdlib.h>

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const std::string inputFile, const std::string dataFile) : 
	_inputFile(inputFile), 
	_dataFile(dataFile),
	_errorFlag(0)
{
	try {
		validateFile();
	} catch (std::exception &e) 
	{
		this->_errorFlag = 1;
	}
	if (!this->_errorFlag)
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

void BitcoinExchange::validateFile()
{
    std::ifstream dataFile(this->_dataFile.c_str());
    std::ifstream inputFile(this->_inputFile.c_str());

	try
	{

        if (!dataFile.is_open() || !inputFile.is_open())
        {
            throw FileNotOpenException();
        }
		std::string inputLine;
		std::string	dataLine;
        if (std::getline(inputFile, inputLine) && std::getline(dataFile, dataLine))
        {
			if (inputLine != "date | value" && inputLine != "date | value\r" && inputLine != "date | value\n")
                throw WrongInputFormatException();
			std::cout << dataLine << std::endl;
			if (dataLine != "date,exchange_rate" && dataLine != "date,exchange_rate\r" && dataLine != "date,exchange_rate\n")
				throw WrongInputFormatException();
        }
        else
        {
            throw EmptyFileException(); 
        }
//		parseDataFile(dataFile);

		parseInputFile(inputFile);
	}
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void	BitcoinExchange::parseDataFile(std::ifstream& database)
{
	std::string	line;

	while (getline(database, line, ' '))
	{
		std::cout << line << std::endl;
	}
}

void	BitcoinExchange::parseInputFile(std::ifstream& input)
{
	std::string line;

    while (std::getline(input, line))
    {
        size_t delim = line.find(" | ");

        if (delim == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, delim);
        std::string valueStr = line.substr(delim + 3);
 
        float value = atof(valueStr.c_str());

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
	return ("ERROR: File wront input format");
}
const char	*BitcoinExchange::EmptyFileException::what() const throw()
{
	return ("ERROR: File can not open");
}




















