/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 19:44:55 by alermi            #+#    #+#             */
/*   Updated: 2026/07/27 20:25:03 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main()
{
    std::cout << "=====================================" << std::endl;
    std::cout << "      1. PDF MANDATORY TEST" << std::endl;
    std::cout << "=====================================" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    std::cout << std::endl;

    std::cout << "=====================================" << std::endl;
    std::cout << "      2. EXCEPTION TESTS" << std::endl;
    std::cout << "=====================================" << std::endl;
    try
    {
        std::cout << "[Test] Attempting to add an element to a full Span..." << std::endl;
        sp.addNumber(42);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n[Test] Attempting to find span with insufficient elements..." << std::endl;
        Span emptySpan(5);
        emptySpan.addNumber(10);
        emptySpan.shortestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=====================================" << std::endl;
    std::cout << "  3. 10,000+ ELEMENTS AND ITERATOR TEST" << std::endl;
    std::cout << "=====================================" << std::endl;
    
    Span bigSpan(15000);
    std::vector<int> randomNumbers;
    
    srand(time(NULL));
    for (int i = 0; i < 10000; i++)
        randomNumbers.push_back(rand() % 1000000);

    try
    {
        std::cout << "[Test] Adding 10,000 numbers at once using iterators..." << std::endl;
        bigSpan.addNumber(randomNumbers.begin(), randomNumbers.end());
        std::cout << "Insertion successful!" << std::endl;

        std::cout << "Big Shortest Span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Big Longest Span: " << bigSpan.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    }

    return 0;
}
