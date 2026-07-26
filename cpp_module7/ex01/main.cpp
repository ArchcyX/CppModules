/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 15:18:29 by alermi            #+#    #+#             */
/*   Updated: 2026/07/14 15:18:30 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <iostream>

void	ft_upperCase(char *str, int size)
{
	int	i = 0;
	for (; i < size; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
	}
}


void	ftPrintArr(char *arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
		std::cout << arr[i] << std::endl;
}

int	main(void)
{
	std::string	arr[] = {"alp", "eren", "lermi"};

	Iter(arr, sizeof(arr), ft_upperCase);
	Iter(arr, sizeof(arr), ftPrintArr);
	return (0);
}
