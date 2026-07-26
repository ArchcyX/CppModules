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



int	main(void)
{
	{
	int	arr[] = {97, 98,99};
	double	arr1[] = {97, 98,99};
	char	arr2[] = {97, 98,99};

	Iter(arr, 3, multiplexer<int>);
	Iter(arr, 3, ftPrintArr<int>);

	Iter(arr1, 3, multiplexer<double>);
	Iter(arr1, 3, ftPrintArr<double>);

	Iter(arr2, 3, multiplexer<char>);
	Iter(arr2, 3, ftPrintArr<char>);
	}
	{	
	const int		arr[] = {97, 98,99};
	const double	arr1[] = {97, 98,99};
	const char		arr2[] = {97, 98,99};

	Iter(arr, 3, ftPrintArr<int>);

	Iter(arr1, 3, ftPrintArr<double>);

	Iter(arr2, 3, ftPrintArr<char>);
	}
	return (0);
}
