/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 13:19:33 by alermi            #+#    #+#             */
/*   Updated: 2026/07/13 13:19:34 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdint.h>


struct Data {
    int         id;
    std::string name;
};

class Serializer
{
    private:
        Serializer();
        ~Serializer();
        Serializer(const Serializer& variant);
        Serializer& operator=(const Serializer& other);
 
	public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};
