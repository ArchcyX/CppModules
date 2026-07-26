/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 15:18:25 by alermi            #+#    #+#             */
/*   Updated: 2026/07/14 16:02:18 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ARRAY_TPP
#define	ARRAY_TPP

#include <exception>
#include <iostream>

template <typename T>
class	Array
{
	private:
			T*		_values;
			size_t	_size;
	public:
		
		class	OutOfBoundException : public std::exception
		{
			public:
				virtual	const char *what() const throw() 
				{
					return ("Array Objects Error: Index is out of bounds");
				}
		};

		Array() : _values(NULL), _size(0) {}
		Array(unsigned int n) : _size(n)
		{
			_values = new T[n];
		}
		~Array()
		{
			delete[] _values;
		}
		Array(const Array &variant) : _values(NULL), _size(0)
		{
			*this = variant;
		}
		Array&	operator=(const Array& other)
		{
			if (this != &other)
			{
				delete[] _values;
				_size = other._size;
				if (_size > 0)
				{
					_values = new	T[_size];
					for (size_t index = 0; index < _size; index++)
						_values[index] = other._values[index];
				}
			}
			else
				_values = NULL;
			return *this;
		}
		T	&operator[](size_t index)
		{
			if (index >= _size)
				throw OutOfBoundException();
			return (_values[index]);
		}
		const T& operator=(size_t index)
		{
			if (index >= _size)
				throw OutOfBoundException();
			return (_values[index]);
		}
};

#endif
