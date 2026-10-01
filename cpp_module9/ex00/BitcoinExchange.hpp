/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 19:46:39 by alermi            #+#    #+#             */
/*   Updated: 2026/10/01 20:25:45 by ax               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <exception>
#include <cstdlib>

class BitcoinExchange
{
private:
    std::string _inputFile;
    std::string _dataFile;
    int _errorFlag;
    std::map<std::string, float> _database; // Veritabanını tutacağımız map

    void validateFile();
    void parseDataFile(std::ifstream& database);
    void parseInputFile(std::ifstream& input);
    bool isValidDate(const std::string& date) const; // Tarih doğrulama fonksiyonu

public:
    BitcoinExchange();
    BitcoinExchange(const std::string inputFile, const std::string dataFile);
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& variant);
    BitcoinExchange& operator=(const BitcoinExchange& other);

    class FileNotOpenException : public std::exception {
        public: virtual const char* what() const throw();
    };
    class WrongInputFormatException : public std::exception {
        public: virtual const char* what() const throw();
    };
    class EmptyFileException : public std::exception {
        public: virtual const char* what() const throw();
    };
};

#endif
