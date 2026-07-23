/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 13:20:24 by alermi            #+#    #+#             */
/*   Updated: 2026/07/13 13:20:47 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScalarConvertor.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 2)
        ScalarConverter::convert(argv[1]);
    else
    {
        std::cout << "Error: Please enter the value" << std::endl;
        std::cout << "Usage: ./convert <value>" << std::endl;
    }
    return (0);
}
