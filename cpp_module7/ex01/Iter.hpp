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

#include <exception>
#include <iostream> 

template <typename T>
class Array {
    private:
        T               *_values;
        unsigned int    _size;

    public:
        // =====================> Exception Class
        class SizeIndexControl : public std::exception {
            public:
                virtual const char *what() const throw() {
                    return "Error: Index is out of bounds!";
                }
        };

        // =====================> OCF Methods (Orthodox Canonical Form)
        
        Array() {
            _values = NULL;
            _size = 0;
        }

        ~Array() { delete[] _values; }

        Array(const Array& variant) {
            _size = variant._size;
            _values = new T[_size]();
            
            for (unsigned int i = 0; i < _size; i++) {
                _values[i] = variant._values[i];
            }
        }

        Array& operator=(const Array& other) {
            if (this != &other) {
                delete[] _values;
                
                _size = other._size;
                _values = new T[_size]();
                
                for (unsigned int i = 0; i < _size; i++) {
                    _values[i] = other._values[i];
                }
            }
            return *this;
        }

        // =====================> Class Control Methods

        Array(unsigned int n) {
            _size = n;
            _values = new T[n]();
        }

        T& operator[](unsigned int index) {
            if (index >= _size) {
                throw SizeIndexControl();
            }
            return _values[index];
        }

        const T& operator[](unsigned int index) const {
            if (index >= _size) {
                throw SizeIndexControl();
            }
            return _values[index];
        }

        unsigned int size(void) const {
            return _size;
        }
};
