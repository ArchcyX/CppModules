/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertor.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 16:17:52 by alermi            #+#    #+#             */
/*   Updated: 2026/07/13 13:20:44 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTOR_HPP
#define SCALARCONVERTOR_HPP

#include <string>

class	ScalarConvertor
{
	private:
		ScalarConvertor();
		~ScalarConvertor();
		ScalarConvertor(const ScalarConvertor& variant);

		static bool	isInt(const std::string& value);
		static bool	isFloat(const std::string& value);
		static bool	isChar(const std::string& value);
		static bool	isDouble(const std::string& value);
		static bool	isPseudoLiteral(const std::string& value);

		static void	printInt(const std::string& value);
		static void printFloatAndDouble(const std::string& literal);
		static void	printChar(const std::string& value);
		static void printPseudoLiteral(const std::string& literal);
	
	public:
		ScalarConvertor& operator=(const ScalarConvertor& other);
		static void	convert(const std::string& literal);


};

#endif
