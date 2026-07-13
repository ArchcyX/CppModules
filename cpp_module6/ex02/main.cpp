/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 13:18:18 by alermi            #+#    #+#             */
/*   Updated: 2026/07/13 18:13:49 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Base.hpp"
#include "./ClassA.hpp"
#include "./ClassB.hpp"
#include "./ClassC.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
#include <sstream>
#include <string>

std::string ptrToString(void* ptr) {
    std::stringstream ss;
    ss << ptr;
    return ss.str();
}

Base	*generate()
{
	int	randomNumber;

	randomNumber = std::rand() % 3;
	switch (randomNumber) 
	{
		case 0:
			return (new	A());
		case 1:
			return (new B());
		case 2:
			return (new	C());
	}
	return (NULL);
}

void	identify(Base *p)
{
    std::cout << "--------------------------" << std::endl;
    std::cout << "||    IDENTIFY (PTR)    ||" << std::endl;
    std::cout << "--------------------------" << std::endl;
	std::cout << "-> this is";
	if (dynamic_cast<A*>(p))
		std::cout << " A class" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << " B class" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << " C class" << std::endl;
	else
	 	std::cout << " a not defined class" << std::endl;
}

void identify(Base& p) {
    std::cout << "--------------------------" << std::endl;
    std::cout << "||    IDENTIFY (REF)    ||" << std::endl;
    std::cout << "--------------------------" << std::endl;

    try {
        A& ref = dynamic_cast<A&>(p); // Referans dönüşümü
        (void)ref;
        std::cout << "ClassA: " << &p << std::endl; // Adresi &p ile alabilirsin
    } catch (std::bad_cast& e) {
        std::cout << "ClassA: Not recommended" << std::endl;
    }

    try {
        B& ref = dynamic_cast<B&>(p);
        (void)ref;
        std::cout << "ClassB: " << &p << std::endl;
    } catch (std::bad_cast& e) {
        std::cout << "ClassB: Not recommended" << std::endl;
    }
    
	try {
        C& ref = dynamic_cast<C&>(p);
        (void)ref;
        std::cout << "ClassC: " << &p << std::endl;
    } catch (std::bad_cast& e) {
        std::cout << "ClassC: Not recommended" << std::endl;
    }
}

int	main(void)
{
	std::srand(std::time(NULL));

	Base	*newBase = generate();
	std::cout << "newBase created : " << &newBase << std::endl;

	identify(newBase);
	identify(*newBase);
	delete newBase;
	return (0);
}
