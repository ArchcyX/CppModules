/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:16:25 by alermi            #+#    #+#             */
/*   Updated: 2026/07/27 19:38:37 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>

class	vectorNotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("!!The element value could not be found in the structure being searched.!!");
		}
};

template <typename T>
typename	T::iterator	easyfind(T& container, int value)
{
	for	(typename T::iterator it = container.begin(); it != container.end(); it++)
	{
		if (*it == value)
			return (it);
	}
	throw vectorNotFoundException();
}

#endif
