/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 19:46:39 by alermi            #+#    #+#             */
/*   Updated: 2026/07/27 20:17:35 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <map>
#include <exception>


class	BitcoinExchange
{
	private:
		std::string						_inputFile;
		std::string						_dataFile;
		std::map<std::string, float>	_data;
		std::map<std::string, float>	_input;
		int								_errorFlag;

	public:
	
		//===================[EXCEPTION CLASS]===========================
		class	FileNotOpenException : public std::exception
		{
			virtual const char	*what() const throw();
		};

		class	WrongInputFormatException : public std::exception
		{
			virtual const char	*what() const throw();
		};

		class	EmptyFileException : public std::exception
		{
			virtual const char	*what() const throw();
		};

		//================[ORHODOX CANNONICAL FORM]======================
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const std::string inputFile, const std::string dataFile);
		BitcoinExchange(const BitcoinExchange& variant);
		BitcoinExchange& operator=(const BitcoinExchange& other);

		//===================[PARSER METHODS]=============================

		void	validateFile();
		void	parseInputFile(std::ifstream& database);
		void	parseDataFile(std::ifstream& database);
		void	processInput();
		
		//==================[GETTER & SETTER]=============================
		void	setData(const std::map<std::string, float>& data);
		std::map<std::string, float>	getData()	const;
};
