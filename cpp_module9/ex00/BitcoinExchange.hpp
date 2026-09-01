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

#include <iostream>
#include <map>
#include <exception>

template <typename Date, typename Value>

class	BitcoinExchange
{
	private:
		std::string				_fileName;
		std::map<Date, Value>	_data;
		std::map<Date, Value>	_input;

	public:
	
		//===================[EXCEPTION CLASS]===========================
		class	FileNotFoundException : std::exception
		{
			virtual const char	*what() const throw();
		};

		//================[ORHODOX CANNONICAL FORM]======================
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& variant);
		BitcoinExchange& operator=(const BitcoinExchange& other);

		//===================[PARSER METHODS]=============================

		
		
		//==================[GETTER & SETTER]=============================
		void	setData(const std::map<Date, Value> _data);
		std::map<Date, Value>	getData()	const;
};
