/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 13:19:37 by alermi            #+#    #+#             */
/*   Updated: 2026/07/13 13:19:38 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer& variant) { (void)variant; }

Serializer& Serializer::operator=(const Serializer& other)
{
	(void)other;
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
