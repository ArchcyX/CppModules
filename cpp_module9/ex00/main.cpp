/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 19:46:39 by alermi            #+#    #+#             */
/*   Updated: 2026/07/27 20:17:35 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <complex>
#include <iostream>
#include <fstream>
#include <string>


int	main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	std::cout << "|=========[CPP MODULE 9]========|" << std::endl;

	const std::string	name = "data.csv";
	std::string	name2=	argv[1];
	BitcoinExchange(name2, name);
}
