/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 16:43:02 by alermi            #+#    #+#             */
/*   Updated: 2026/03/23 16:48:07 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"

void    header_monitor(std::string title, std::string color)
{
    std::cout << color << "\n|=============[ " << title << " ]=============|" << RESET << std::endl;
}

int    main(void)
{
    header_monitor("Test 1: Valid Bureaucrats", GREEN);
    try {
        Bureaucrat b1("Ali", 25);
        std::cout << b1 << std::endl;
        Bureaucrat b2("Veli", 1);
        std::cout << b2 << std::endl;
        Bureaucrat b3("John", 150);
        std::cout << b3 << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    header_monitor("Test 2: Grade Too High Initial", YELLOW);
    try {
        Bureaucrat b1("TooHigh", 0);
        std::cout << b1 << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    header_monitor("Test 3: Grade Too Low Initial", YELLOW);
    try {
        Bureaucrat b1("TooLow", 151);
        std::cout << b1 << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    header_monitor("Test 4: Increment Error", MAGENTA);
    try {
        Bureaucrat b1("Top", 1);
        std::cout << b1 << std::endl;
        b1.incrementGrade();
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    header_monitor("Test 5: Decrement Error", MAGENTA);
    try {
        Bureaucrat b1("Bottom", 150);
        std::cout << b1 << std::endl;
        b1.decrementGrade();
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    header_monitor("Test 6: Normal Increment & Decrement", CYAN);
    try {
        Bureaucrat b1("Normal", 75);
        std::cout << b1 << std::endl;
        b1.incrementGrade();
        std::cout << "After Increment: " << b1 << std::endl;
        b1.decrementGrade();
        std::cout << "After Decrement: " << b1 << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    return (0);
}
