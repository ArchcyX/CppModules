/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:09:41 by alermi            #+#    #+#             */
/*   Updated: 2025/11/08 19:21:32 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(void)
{
	Harl	harl_person;
	std::string levels[4] = {"INFO", "WARNING", "ERROR", "DEBUG"};

	for (int i = 0; i < 4; i++)
		harl_person.complain(levels[i]);
	return (0);
}
