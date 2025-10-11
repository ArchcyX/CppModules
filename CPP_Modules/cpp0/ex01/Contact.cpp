/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:02:46 by alermi            #+#    #+#             */
/*   Updated: 2025/09/05 17:10:34 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setFirstName(const std::string& input) { firstName = input; }
void Contact::setLastName(const std::string& input) { lastName = input; }
void Contact::setNickname(const std::string& input) { nickname = input; }
void Contact::setPhoneNumber(const std::string& input) { phoneNumber = input; }
void Contact::setDarkestSecret(const std::string& input) { darkestSecret = input; }

std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getNickname() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getDarkestSecret() const { return darkestSecret; }

