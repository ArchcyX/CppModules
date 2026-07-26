/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 15:18:25 by alermi            #+#    #+#             */
/*   Updated: 2026/07/14 16:02:18 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T, typename F, typename Len>
void	Iter(T *array, const Len size, F function)
{
	for	(Len i = 0; i < size; i++)
	{
		function(array[i]);
	}
}

template <typename T>
void	multiplexer(T &value)
{
	value *= 2;
}

template <>
void	multiplexer<char>(char &value)
{
	value += 1;
}

template <typename T>
void	ftPrintArr(T value)
{
	std::cout << value << std::endl;
}
