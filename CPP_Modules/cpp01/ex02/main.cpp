/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 04:58:47 by alermi            #+#    #+#             */
/*   Updated: 2025/10/11 05:04:51 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	str;
	std::string* stringPTR;
	std::string& stringREF = str;

	str = "HI THIS IS BRAIN";
	stringPTR = &str;
	stringREF =  str;
	std::cout << "adress of str:" << &str << std::endl;
	std::cout << "adress of stringPTR" << stringPTR << std::endl;
	std::cout << "adress of stringREF" << &stringREF << std::endl;
	std::cout << "==============================" << std::endl;
	std::cout << "value of str:" << str << std::endl;
	std::cout << "value of stringPTR: " << *stringPTR << std::endl;
	std::cout << "value of stringREF: " << stringREF << std::endl;
	return (0);
}
