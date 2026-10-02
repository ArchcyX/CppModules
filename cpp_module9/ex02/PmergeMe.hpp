/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ax <alermi@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 11:12:53 by ax                #+#    #+#             */
/*   Updated: 2026/10/02 11:59:07 by ax               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <exception>

class PmergeMe
{
	private:
		std::vector<unsigned int>	_vec;
		std::deque<unsigned int>	_deq;
		double						_vecTime;
		double						_deqTime;

		void	_validateArguments(int argc, char **argv) const;
		void	_printBefore(int argc, char **argv) const;
		void	_printAfter() const;

		void	_processVector(int argc, char **argv);
		void	_processDeque(int argc, char **argv);

		void	_sortVector(std::vector<unsigned int>& vec);
		void	_sortDeque(std::deque<unsigned int>& deq);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void	execute(int argc, char **argv);

		class InvalidInputException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

#endif
