/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ax <alermi@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 11:12:56 by ax                #+#    #+#             */
/*   Updated: 2026/10/02 12:00:52 by ax               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMe.hpp"

#include "PmergeMe.hpp"

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

bool	PmergeMe::_parseNumber(const std::string& str, unsigned int& out)
{

};

void	PmergeMe::_validateArguments(int argc, char **argv)
{

};

void	PmergeMe::_printBefore(int argc, char **argv)
{

};

void	PmergeMe::_printAfter()
{

};

double	PmergeMe::_getCurrentTime()
{

};

std::size_t	PmergeMe::_jacobsthal(std::size_t k)
{

};

void	PmergeMe::_processVector(int argc, char **argv)
{

};

void	PmergeMe::_processDeque(int argc, char **argv)
{

};

void	PmergeMe::_sortVector(std::vector<unsigned int>& vec)
{

};

void	PmergeMe::_sortDeque(std::deque<unsigned int>& deq)
{

};


void	PmergeMe::execute(int argc, char **argv)
{

};
