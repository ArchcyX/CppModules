/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:59:20 by alermi            #+#    #+#             */
/*   Updated: 2025/09/05 17:12:45 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PhoneBook.cpp
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

PhoneBook::PhoneBook() {
    contactCount = 0;
    nextIndex = 0;
}

std::string getInput(const std::string& prompt) {
    std::string input;
    do {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "Bu alan boş bırakılamaz. Tekrar girin.\n";
    } while (input.empty());
    return input;
}

void PhoneBook::addContact() {
    Contact newContact;

    newContact.setFirstName(getInput("İsim: "));
    newContact.setLastName(getInput("Soyisim: "));
    newContact.setNickname(getInput("Lakap: "));
    newContact.setPhoneNumber(getInput("Telefon No: "));
    newContact.setDarkestSecret(getInput("En karanlık sır: "));

    contacts[nextIndex] = newContact;

    if (contactCount < 8)
        contactCount++;

    nextIndex = (nextIndex + 1) % 8;

    std::cout << "✅ Kişi başarıyla eklendi.\n";
}

std::string formatField(const std::string& str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    else
        return str;
}

void PhoneBook::searchContacts() const {
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "\n";

    for (int i = 0; i < contactCount; i++) {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << formatField(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << formatField(contacts[i].getLastName()) << "|"
                  << std::setw(10) << formatField(contacts[i].getNickname()) << "\n";
    }
}

void PhoneBook::showContactDetails(int index) const {
    if (index < 0 || index >= contactCount) {
        std::cout << "❌ Geçersiz indeks!\n";
        return;
    }

    const Contact& c = contacts[index];

    std::cout << "İsim: " << c.getFirstName() << "\n";
    std::cout << "Soyisim: " << c.getLastName() << "\n";
    std::cout << "Lakap: " << c.getNickname() << "\n";
    std::cout << "Telefon No: " << c.getPhoneNumber() << "\n";
    std::cout << "Sır: " << c.getDarkestSecret() << "\n";
}
