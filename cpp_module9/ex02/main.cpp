/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ax <alermi@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 11:12:49 by ax                #+#    #+#             */
/*   Updated: 2026/10/02 12:15:07 by ax               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMe.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "Error: Wrong Input" << std::endl;
		return (1);
	}
	(void) argv;
	PmergeMe();

	return (0);
}
