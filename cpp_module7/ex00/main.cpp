/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 12:53:17 by alermi            #+#    #+#             */
/*   Updated: 2026/07/14 13:06:07 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"

int	main(void)
{
	int	numberOne = 10;
	int	numberTwo = 12;

	std::cout << "this addition result value:" << add(numberOne, numberTwo) << std::endl;

	char	valueOne = 'a';
	char	valueTwo = 'b';

	std::cout << "this addition result value:" << add(valueOne, valueTwo) << std::endl;

	std::cout << "this addition result value" << add(valueOne, valueTwo) << std::endl;
}
