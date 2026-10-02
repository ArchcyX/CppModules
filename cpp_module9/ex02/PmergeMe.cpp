/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ax <alermi@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 11:12:56 by ax                #+#    #+#             */
/*   Updated: 2026/10/02 16:04:46 by ax               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMe.hpp"
#include <climits>
#include <iostream>

PmergeMe::PmergeMe() : _vecTime(0.0), _deqTime(0.0)
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& variant) : _vec(variant._vec), 
                                            _deq(variant._deq), 
                                            _vecTime(variant._vecTime), 
                                            _deqTime(variant._deqTime)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        this->_vec = other._vec;
        this->_deq = other._deq;
        this->_vecTime = other._vecTime;
        this->_deqTime = other._deqTime;
    }
    return (*this);
}

bool PmergeMe::_parseNumber(const std::string& str, unsigned int& out) const
{
    if (str.empty())
        return (false);

    size_t i = 0;

    if (str[i] == '+')
        if (++i == str.length())
            return (false);

    unsigned int tempValue = 0;

    for (; i < str.length(); ++i)
    {
        if (!std::isdigit(str[i]))
            return (false);

        unsigned int digit = str[i] - '0';

        if (tempValue > (UINT_MAX - digit) / 10)
            return (false);

        tempValue = tempValue * 10 + digit;
    }

    out = tempValue;
 
    return (true);
}

void	PmergeMe::_validateArguments(int argc, char **argv) const
{
	if	(argc == 1)
		throw InvalidInputException("Error: Invalid argument count");
	std::cout << "Baba buraya geliyor mu?" << std::endl;
	return ;
}

void	PmergeMe::_printBefore(int argc, char **argv) const
{

}

void	PmergeMe::_printAfter() const
{

}

double	PmergeMe::_getCurrentTime() const
{
	return (0);
}

std::size_t	PmergeMe::_jacobsthal(std::size_t k) const
{
	return (0);
}

void	PmergeMe::_processVector(int argc, char **argv)
{

}

void	PmergeMe::_processDeque(int argc, char **argv)
{

}

void	PmergeMe::_sortVector(std::vector<unsigned int>& vec)
{

}

void	PmergeMe::_sortDeque(std::deque<unsigned int>& deq)
{

}

void	PmergeMe::execute(int argc, char **argv)
{

}

const char *PmergeMe::InvalidInputException::what() const throw()
{
    return ("Error: Invalid Argument Input");
}
