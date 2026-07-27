/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 19:44:55 by alermi            #+#    #+#             */
/*   Updated: 2026/07/27 20:45:05 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"

int main()
{
    std::cout << CYAN << "=====================================" << RESET << std::endl;
    std::cout << CYAN << "      1. PDF MANDATORY TEST" << RESET << std::endl;
    std::cout << CYAN << "=====================================" << RESET << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << GREEN << "Shortest Span: " << sp.shortestSpan() << RESET << std::endl;
    std::cout << GREEN << "Longest Span: " << sp.longestSpan() << RESET << std::endl;
    std::cout << std::endl;

    std::cout << CYAN << "=====================================" << RESET << std::endl;
    std::cout << CYAN << "      2. EXCEPTION TESTS" << RESET << std::endl;
    std::cout << CYAN << "=====================================" << RESET << std::endl;
    try
    {
        std::cout << YELLOW << "[Test] Attempting to add an element to a full Span..." << RESET << std::endl;
        sp.addNumber(42);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Caught Exception: " << e.what() << RESET << std::endl;
    }

    try
    {
        std::cout << YELLOW << "\n[Test] Attempting to find span with insufficient elements..." << RESET << std::endl;
        Span emptySpan(5);
        emptySpan.addNumber(10);
        emptySpan.shortestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Caught Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    std::cout << CYAN << "=====================================" << RESET << std::endl;
    std::cout << CYAN << "  3. 10,000+ ELEMENTS AND ITERATOR TEST" << RESET << std::endl;
    std::cout << CYAN << "=====================================" << RESET << std::endl;
    
    Span bigSpan(15000);
    std::vector<int> randomNumbers;
    
    srand(time(NULL));
    for (int i = 0; i < 10000; i++)
        randomNumbers.push_back(rand() % 1000000);

    try
    {
        std::cout << YELLOW << "[Test] Adding 10,000 numbers at once using iterators..." << RESET << std::endl;
        bigSpan.addNumber(randomNumbers.begin(), randomNumbers.end());
        std::cout << GREEN << "Insertion successful!" << RESET << std::endl;

        std::cout << GREEN << "Big Shortest Span: " << bigSpan.shortestSpan() << RESET << std::endl;
        std::cout << GREEN << "Big Longest Span: " << bigSpan.longestSpan() << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Caught Exception: " << e.what() << RESET << std::endl;
    }

    return 0;
}
