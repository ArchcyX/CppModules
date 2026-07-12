/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarCOnvertor.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 16:17:52 by alermi            #+#    #+#             */
/*   Updated: 2026/07/10 16:19:09 by alermi           ###   ########.fr       */
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
	
	public:
		ScalarConvertor& operator=(const ScalarConvertor& other);
		static void	convert(const std::string& literal);

		bool	isInt(const std::string& value);
		bool	isFloat(const std::string& value);
		bool	isChar(const std::string& value);
		bool	isDouble(const std::string& value);
		bool	isPseudoLiteral(const std::string& value);

		void	printInt(const std::string& value);
		void	printFloatanDouble(const std::string& value);
		void	printChar(const std::string& value);
		void	printPreudoLiteral(const std::string& value);
};

#endif
