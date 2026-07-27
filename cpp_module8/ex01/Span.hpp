/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 19:46:44 by alermi            #+#    #+#             */
/*   Updated: 2026/07/27 20:25:07 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>

class Span
{
    private:
        std::vector<int>    _vList;
        unsigned int        _N;

    public:

        //===================================
        //       Orthodox Canonical Form
        //===================================
        Span();
        Span(unsigned int N);
        ~Span();
        Span(const Span& variant);
        Span&    operator=(const Span& other);

        //===================================
        //             Exceptions
        //===================================
        class SpanFullException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class NotEnoughElementsException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        //===================================
        //           Member Methods
        //===================================
        void            addNumber(int number);
        unsigned int    shortestSpan();
        unsigned int    longestSpan();

        //===================================
        //       Template Member Method
        //===================================
        template <typename Iterator>
        void    addNumber(Iterator begin, Iterator end)
        {
            unsigned int distance = std::distance(begin, end);
            
            if (_vList.size() + distance > _N)
                throw SpanFullException();
                
            _vList.insert(_vList.end(), begin, end);
        }
};

#endif
