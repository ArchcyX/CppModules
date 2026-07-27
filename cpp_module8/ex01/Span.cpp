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

#include "Span.hpp"
#include <iostream>
#include <algorithm>

//===================================
//       Orthodox Canonical Form
//===================================

Span::Span() : _N(0)
{
    std::cout << "Default Constructor Called" << std::endl;
}

Span::Span(unsigned int N) : _N(N)
{
    std::cout << "Constructor Called" << std::endl;
}

Span::~Span()
{
    std::cout << "Destructor Called" << std::endl;
}

Span::Span(const Span& variant) : _vList(variant._vList), _N(variant._N)
{
    std::cout << "Copy Constructor Called" << std::endl;
}

Span& Span::operator=(const Span& other)
{
    std::cout << "Assignment Operator Called" << std::endl;
    if (this != &other)
    {
        this->_N = other._N;
        this->_vList = other._vList;
    }
    return *this;
}

//===================================
//             Exceptions
//===================================

const char* Span::SpanFullException::what() const throw()
{
		return "The span element is currently completely full";
}

const char* Span::NotEnoughElementsException::what() const throw()
{
    return "There are not enough elements in the vector for the current function";
}

//===================================
//           Member Methods
//===================================

void Span::addNumber(int number)
{
	if (this->_vList.size() == this->_N)
		throw SpanFullException();
	this->_vList.push_back(number);
}

static unsigned int difference(const std::vector<int>& sortedList)
{
    unsigned int val1 = static_cast<unsigned int>(sortedList[1]);
    unsigned int val2 = static_cast<unsigned int>(sortedList[0]);
    unsigned int minSpan = val1 - val2;

    for (size_t i = 2; i < sortedList.size(); ++i)
    {
        unsigned int currentVal1 = static_cast<unsigned int>(sortedList[i]);
        unsigned int currentVal2 = static_cast<unsigned int>(sortedList[i - 1]);
        unsigned int currentSpan = currentVal1 - currentVal2;
        
        if (currentSpan < minSpan)
            minSpan = currentSpan;
    }

    return (minSpan);
}

unsigned int Span::shortestSpan()
{
    if (this->_vList.size() < 2)
        throw NotEnoughElementsException();

    std::vector<int> sortedList = this->_vList;
    std::sort(sortedList.begin(), sortedList.end());

    return difference(sortedList);
}

static unsigned int maxDifference(const std::vector<int>& list)
{
    int minVal = *std::min_element(list.begin(), list.end());
    int maxVal = *std::max_element(list.begin(), list.end());

    return static_cast<unsigned int>(maxVal) - static_cast<unsigned int>(minVal);
}

unsigned int Span::longestSpan()
{
    if (this->_vList.size() < 2)
        throw NotEnoughElementsException();

    return maxDifference(this->_vList);
}
