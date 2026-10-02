/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ax <alermi@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 20:31:59 by ax                #+#    #+#             */
/*   Updated: 2026/10/02 13:31:16 by ax               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./RPN.hpp"

#include "RPN.hpp"
#include <sstream>
#include <cctype>

RPN::RPN()
{
}

RPN::RPN(const RPN& other)
{
    *this = other;
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
    {
        this->_stack = other._stack;
    }
    return *this;
}

RPN::~RPN()
{
}

void RPN::performOperation(char op)
{
    if (_stack.size() < 2)
        throw ErrorException();

    long right_operand = _stack.top();
    _stack.pop();
    
    long left_operand = _stack.top();
    _stack.pop();

    long result = 0;

    switch (op)
    {
        case '+':
            result = left_operand + right_operand;
            break;
        case '-':
            result = left_operand - right_operand;
            break;
        case '*':
            result = left_operand * right_operand;
            break;
        case '/':
            if (right_operand == 0)
                throw ErrorException();
            result = left_operand / right_operand;
            break;
    }
    _stack.push(result);
}

void RPN::calculate(const std::string& expression)
{
    std::stringstream ss(expression);
    std::string token;

    try
    {
        while (ss >> token)
        {
            if (token == "+" || token == "-" || token == "*" || token == "/")
                performOperation(token[0]);
            else
            {
                if (token.length() == 1 && std::isdigit(token[0]))
                    _stack.push(token[0] - '0');
                else
                    throw ErrorException();
            }
        }

        if (_stack.size() != 1)
            throw ErrorException();

        std::cout << _stack.top() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    while (!_stack.empty())
        _stack.pop();
}

const char* RPN::ErrorException::what() const throw()
{
    return ("Error");
}
