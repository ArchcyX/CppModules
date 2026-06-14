/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 16:43:02 by alermi            #+#    #+#             */
/*   Updated: 2026/03/23 16:48:07 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "--- Test 1: Valid Bureaucrats ---" << std::endl;
	try {
		Bureaucrat b1("Alp", 25);
		std::cout << b1 << std::endl;
		Bureaucrat b2("Enver", 1);
		std::cout << b2 << std::endl;
		Bureaucrat b3("John", 150);
		std::cout << b3 << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 2: Grade Too High Initial ---" << std::endl;
	try {
		Bureaucrat b1("TooHigh", 0);
		std::cout << b1 << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 3: Grade Too Low Initial ---" << std::endl;
	try {
		Bureaucrat b1("TooLow", 151);
		std::cout << b1 << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 4: Increment Error ---" << std::endl;
	try {
		Bureaucrat b1("Top", 1);
		std::cout << b1 << std::endl;
		b1.incrementGrade();
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 5: Decrement Error ---" << std::endl;
	try {
		Bureaucrat b1("Bottom", 150);
		std::cout << b1 << std::endl;
		b1.decrementGrade();
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 6: Normal Increment & Decrement ---" << std::endl;
	try {
		Bureaucrat b1("Normal", 75);
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << "After Increment: " << b1 << std::endl;
		b1.decrementGrade();
		std::cout << "After Decrement: " << b1 << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return (0);
}
