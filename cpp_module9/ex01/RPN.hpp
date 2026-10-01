/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ax <alermi@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 20:31:51 by ax                #+#    #+#             */
/*   Updated: 2026/10/01 22:01:30 by ax               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <stdexcept>

typedef enum e_operator
{
	ADD = 0,
	SUB = 1,
	MUL = 2,
	DIV = 3
};

typename struct s_token
{
	bool	isOperator;
	size_t	value;
}	t_token;

class	RPN
{
	private:
		
		std::stack<t_token>	_valuesStack;
		bool				_isValidNumber(char c) const;
		bool				_isOperatorChar(char c) const;

		e_operator	_determineOperator(char c) const;
		void		_performOperation(e_operator op);

	public:
		
		RPN();
		~RPN();
		RPN(const RPN& variant);
		RPN& operator=(const RPN& other);

		bool	checkStack(std::stack<t_token> &stacl);
		void	calculate(const std::string& expression);

		class	ErrorException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
