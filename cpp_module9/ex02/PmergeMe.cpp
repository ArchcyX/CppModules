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

#include "PmergeMe.hpp"
#include <iostream>
#include <iomanip>
#include <climits>
#include <cctype>
#include <sys/time.h>
#include <algorithm>
#include <utility>
#include <cstddef>

/* ************************************************************************** */
/*                          Orthodox Canonical Form                           */
/* ************************************************************************** */

PmergeMe::PmergeMe() : _vecTime(0.0), _deqTime(0.0)
{
}

PmergeMe::PmergeMe(const PmergeMe& other) : _vec(other._vec),
                                            _deq(other._deq),
                                            _vecTime(other._vecTime),
                                            _deqTime(other._deqTime)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vec = other._vec;
        _deq = other._deq;
        _vecTime = other._vecTime;
        _deqTime = other._deqTime;
    }
    return (*this);
}

PmergeMe::~PmergeMe()
{
}

/* ************************************************************************** */
/*                                  Methods                                   */
/* ************************************************************************** */

extern __inline__ bool 
	_parseNumber(const std::string& str, unsigned int& out)
{
    if (str.empty())
        return (false);

    std::size_t i = 0;

    if (str[i] == '+')
    {
        ++i;
        if (i == str.length())
            return (false);
    }

    unsigned int tempValue = 0;

    for (; i < str.length(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            return (false);

        unsigned int digit = static_cast<unsigned int>(str[i] - '0');

        if (tempValue > (UINT_MAX - digit) / 10)
            return (false);

        tempValue = tempValue * 10 + digit;
    }

    out = tempValue;
    return (true);
}

void PmergeMe::_validateArguments(int argc, char **argv) const
{
    if (argc < 2)
        throw InvalidInputException();

    unsigned int temp;
    for (int i = 1; i < argc; ++i)
    {
        if (!_parseNumber(argv[i], temp))
            throw InvalidInputException();
    }
}

void PmergeMe::_printBefore(int argc, char **argv) const
{
    std::cout << "Before: ";
    for (int i = 1; i < argc; ++i)
    {
        std::cout << argv[i];
        if (i < argc - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::_printAfter() const
{
    std::cout << "After:  ";
    for (std::size_t i = 0; i < _vec.size(); ++i)
    {
        std::cout << _vec[i];
        if (i + 1 < _vec.size())
            std::cout << " ";
    }
    std::cout << std::endl;
}

extern __inline__ void
	_printTimeLine(const std::string& containerName, std::size_t size, double time)
{
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << size
              << " elements with " << containerName << " : " << time << " us" << std::endl;
}

/* ************************************************************************** */
/*                                Time Sequence                               */
/* ************************************************************************** */

extern __inline__
	double _getCurrentTime()
{
	struct timespec ts;
    
    clock_gettime(CLOCK_MONOTONIC, &ts);
    
    return (static_cast<double>(ts.tv_sec) * 1000000.0 + 
            static_cast<double>(ts.tv_nsec) / 1000.0);
}
/* ************************************************************************** */
/*                               Process Methods                              */
/* ************************************************************************** */

void PmergeMe::_processVector(int argc, char **argv)
{
    _vec.clear();
    for (int i = 1; i < argc; ++i)
    {
        unsigned int num = 0;
        _parseNumber(argv[i], num);
        _vec.push_back(num);
    }
    _sortVector(_vec);
}

void PmergeMe::_processDeque(int argc, char **argv)
{
    _deq.clear();
    for (int i = 1; i < argc; ++i)
    {
        unsigned int num = 0;
        _parseNumber(argv[i], num);
        _deq.push_back(num);
    }
    _sortDeque(_deq);
}

extern __inline__ std::size_t
	_jacobsthal(std::size_t k)
{
    if (k == 0) return 0;
    if (k == 1) return 1;
    
    std::size_t prev2 = 0;
    std::size_t prev1 = 1;
    std::size_t current = 0;
    
    for (std::size_t i = 2; i <= k; ++i)
    {
        current = prev1 + 2 * prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return current;
}

/* ************************************************************************** */
/*                               Sorting Helpers                              */
/* ************************************************************************** */

extern __inline__ void
    _createPairsVector(std::vector<unsigned int>& vec, 
                       std::vector<std::pair<unsigned int, unsigned int> >& pairs, 
                       std::vector<unsigned int>& mainChain, 
                       unsigned int& straggler, bool& hasStraggler)
{
    hasStraggler = (vec.size() % 2 != 0);

    std::size_t loopLimit = vec.size();
    if (hasStraggler)
    {
        straggler = vec.back();
        loopLimit = loopLimit - 1;
    }

    for (std::size_t i = 0; i < loopLimit; i += 2)
    {
        unsigned int a = vec[i];
        unsigned int b = vec[i + 1];
        
        if (a < b) 
        {
            std::swap(a, b);
        }

        pairs.push_back(std::make_pair(a, b));
        mainChain.push_back(a);
    }
}

extern __inline__ void
	_buildPendVector(const std::vector<unsigned int>& mainChain, 
                             const std::vector<std::pair<unsigned int, unsigned int> >& pairs, 
                             std::vector<unsigned int>& pend)
{
    for (std::size_t i = 0; i < mainChain.size(); ++i)
    {
        for (std::size_t j = 0; j < pairs.size(); ++j)
        {
            if (mainChain[i] == pairs[j].first)
            {
                pend.push_back(pairs[j].second);
                break;
            }
        }
    }
}

extern __inline__ void
	_insertJacobsthalVector(std::vector<unsigned int>& mainChain, 
                                    const std::vector<unsigned int>& pend, 
                                    const PmergeMe* instance)
{
    if (pend.empty()) return;
    
    mainChain.insert(mainChain.begin(), pend[0]);

    std::size_t pendSize = pend.size();
    std::size_t jacobIndex = 3;
    std::size_t lastJacob = 1;

    while (lastJacob < pendSize)
    {
        std::size_t currentJacob = _jacobsthal(jacobIndex);
        if (currentJacob > pendSize)
            currentJacob = pendSize;

        for (std::size_t i = currentJacob; i > lastJacob; --i)
        {
            unsigned int elementToInsert = pend[i - 1];
            unsigned int corresponding_a = mainChain.back();
            
            std::vector<unsigned int>::iterator bound = mainChain.end();
            std::vector<unsigned int>::iterator it = std::lower_bound(mainChain.begin(), bound, elementToInsert);
            mainChain.insert(it, elementToInsert);
        }
        lastJacob = currentJacob;
        jacobIndex++;
    }
}

extern __inline__ void
	_insertStragglerVector(std::vector<unsigned int>& mainChain, unsigned int straggler, bool hasStraggler)
{
    if (hasStraggler)
    {
        std::vector<unsigned int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(it, straggler);
    }
}

/* ************************************************************************** */
/*                                Sorting Methods                             */
/* ************************************************************************** */

void PmergeMe::_sortVector(std::vector<unsigned int>& vec)
{
    if (vec.size() < 2)
        return;

    std::vector<std::pair<unsigned int, unsigned int> > pairs;
    std::vector<unsigned int> mainChain;
    std::vector<unsigned int> pend;
    unsigned int straggler = 0;
    bool hasStraggler = false;

    _createPairsVector(vec, pairs, mainChain, straggler, hasStraggler);
    _sortVector(mainChain);
    _buildPendVector(mainChain, pairs, pend);
    _insertJacobsthalVector(mainChain, pend, this);
    _insertStragglerVector(mainChain, straggler, hasStraggler);

    vec = mainChain;
}

void PmergeMe::_sortDeque(std::deque<unsigned int>& deq)
{
    if (deq.size() < 2)
        return;

    std::deque<unsigned int> mainChain;
    std::deque<unsigned int> pend;
    bool hasStraggler = (deq.size() % 2 != 0);
    unsigned int straggler = 0;

    if (hasStraggler)
        straggler = deq.back();

    std::deque< std::pair<unsigned int, unsigned int> > pairs;
    for (std::size_t i = 0; i < deq.size() - (hasStraggler ? 1 : 0); i += 2)
    {
        unsigned int a = deq[i];
        unsigned int b = deq[i+1];
        if (a < b) std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
        mainChain.push_back(a);
    }

    _sortDeque(mainChain);

    for (std::size_t i = 0; i < mainChain.size(); ++i)
    {
        for (std::size_t j = 0; j < pairs.size(); ++j)
        {
            if (mainChain[i] == pairs[j].first)
            {
                pend.push_back(pairs[j].second);
                break;
            }
        }
    }

    if (!pend.empty())
        mainChain.insert(mainChain.begin(), pend[0]);

    std::size_t pendSize = pend.size();
    std::size_t jacobIndex = 3;
    std::size_t lastJacob = 1;

    while (lastJacob < pendSize)
    {
        std::size_t currentJacob = _jacobsthal(jacobIndex);
        if (currentJacob > pendSize)
            currentJacob = pendSize;

        for (std::size_t i = currentJacob; i > lastJacob; --i)
        {
            unsigned int elementToInsert = pend[i - 1];
            std::deque<unsigned int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), elementToInsert);
            mainChain.insert(it, elementToInsert);
        }
        lastJacob = currentJacob;
        jacobIndex++;
    }

    if (hasStraggler)
    {
        std::deque<unsigned int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(it, straggler);
    }

    deq = mainChain;
}

/* ************************************************************************** */
/*                                Execute / Main                              */
/* ************************************************************************** */

void PmergeMe::execute(int argc, char **argv)
{
    _validateArguments(argc, argv);
    _printBefore(argc, argv);

    double startVec = _getCurrentTime();
    _processVector(argc, argv);
    _vecTime = _getCurrentTime() - startVec;

    double startDeq = _getCurrentTime();
    _processDeque(argc, argv);
    _deqTime = _getCurrentTime() - startDeq;

    _printAfter();
    _printTimeLine("std::vector", _vec.size(), _vecTime);
    _printTimeLine("std::deque ", _deq.size(), _deqTime);
}

const char *PmergeMe::InvalidInputException::what() const throw()
{
    return ("Error");
}
