/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ax <alermi@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 10:05:44 by ax                #+#    #+#             */
/*   Updated: 2026/10/01 20:27:14 by ax               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <sstream>

BitcoinExchange::BitcoinExchange() : _inputFile(""), _dataFile(""), _errorFlag(0) {}

BitcoinExchange::BitcoinExchange(const std::string inputFile, const std::string dataFile) : 
    _inputFile(inputFile), 
    _dataFile(dataFile),
    _errorFlag(0)
{
    try {
        validateFile();
    } catch (std::exception &e) {
        this->_errorFlag = 1;
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& variant)
{
    *this = variant;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
        this->_inputFile = other._inputFile;
        this->_dataFile = other._dataFile;
        this->_errorFlag = other._errorFlag;
        this->_database = other._database;
    }
    return *this;
}

void BitcoinExchange::validateFile()
{
    std::ifstream dataFile(this->_dataFile.c_str());
    std::ifstream inputFile(this->_inputFile.c_str());

    if (!dataFile.is_open() || !inputFile.is_open())
        throw FileNotOpenException();

    std::string inputLine, dataLine;
    
    if (std::getline(inputFile, inputLine) && std::getline(dataFile, dataLine))
    {
        if (inputLine != "date | value" && inputLine != "date | value\r")
            throw WrongInputFormatException();
            
        if (dataLine != "date,exchange_rate" && dataLine != "date,exchange_rate\r")
            throw WrongInputFormatException();
    }
    else
    {
        throw EmptyFileException(); 
    }

    parseDataFile(dataFile);
    parseInputFile(inputFile);
}

void BitcoinExchange::parseDataFile(std::ifstream& database)
{
    std::string line;

    while (std::getline(database, line))
    {
        size_t delim = line.find(',');
        if (delim != std::string::npos)
        {
            std::string date = line.substr(0, delim);
            float rate = atof(line.substr(delim + 1).c_str());
            _database[date] = rate;
        }
    }
}

void BitcoinExchange::parseInputFile(std::ifstream& input)
{
    std::string line;

    while (std::getline(input, line))
    {
        if (line.empty()) continue;

        size_t delim = line.find(" | ");

        if (delim == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, delim);
        std::string valueStr = line.substr(delim + 3);

        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        float value = atof(valueStr.c_str());

        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        std::map<std::string, float>::iterator it = _database.upper_bound(date);

        if (it == _database.begin()) {
            std::cerr << "Error: Date is older than any record in database => " << date << std::endl;
            continue;
        }

        --it; 

        std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
    }
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;

    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) continue;
        if (!isdigit(date[i])) return false;
    }

    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (year < 2009) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;

    if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
        return false;

    if (month == 2) {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > 29 || (day == 29 && !isLeap))
            return false;
    }

    return true;
}

const char *BitcoinExchange::FileNotOpenException::what() const throw() {
    return ("File could not be opened.");
}

const char *BitcoinExchange::WrongInputFormatException::what() const throw() {
    return ("File has a wrong header format.");
}

const char *BitcoinExchange::EmptyFileException::what() const throw() {
    return ("File is empty.");
}















