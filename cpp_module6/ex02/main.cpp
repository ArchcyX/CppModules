/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 13:18:18 by alermi            #+#    #+#             */
/*   Updated: 2026/07/13 15:28:10 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Base.hpp"
#include "./ClassA.hpp"
#include "./ClassB.hpp"
#include "./ClassC.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>


Base	*generate()
{
	int	randomNumber;

	randomNumber = std::rand() % 3;
	switch (randomNumber) 
	{
		case 0:
			new	A();
		case 1:
			new B();
		case 2:
			new	C();
	}
	return (NULL);
}

void	identify(Base *p)
{
	(void)p;
}

void	identify(Base& p)
{
	(void)p;
}

int	main(void)
{

	std::srand(std::time(NULL));
	generate();
	return (0);
}
