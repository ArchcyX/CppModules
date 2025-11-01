/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 12:11:28 by alermi            #+#    #+#             */
/*   Updated: 2025/09/06 18:35:26 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iomanip>
#include <cstdlib>

Phonebook::Phonebook() : numContacts(0) {}

void Phonebook::addContact(const Contact &newContact)
{
	static int	old_contact = 0;

    if (numContacts < 8)
    {
        contacts[numContacts] = newContact;
        numContacts++;
    }
    else
    {
		if (old_contact == 8)
			old_contact = 0;
        std::cout << "Phonebook is full. Oldest contact will be replaced: "
                  << contacts[0].getFirstName() << std::endl;
        contacts[old_contact++] = newContact;
    }
}

std::string Phonebook::formatField(const std::string &str) const
{
    if (str.length() > 10)
    {
        size_t bytePos = 0;
        int charCount = 0;
        size_t lastSafePos = 0;
        
        while (bytePos < str.length() && charCount < 9)
        {
            unsigned char c = str[bytePos];
            
            if ((c & 0x80) == 0)
            {
                lastSafePos = bytePos + 1;
                charCount++;
                bytePos++;
            }
            else if ((c & 0xC0) == 0xC0)
            {
                bytePos++;
                while (bytePos < str.length() && (str[bytePos] & 0xC0) == 0x80)
                    bytePos++;
                if (charCount < 9)
                {
                    lastSafePos = bytePos;
                    charCount++;
                }
                else
                    break;
            }
            else
                bytePos++;
        }
        
        std::string result = str.substr(0, lastSafePos) + ".";
        while (result.length() < 10)
            result += " ";
        return result;
    }
    
    std::string result = str;
    while (result.length() < 10)
        result += " ";
        
    return result;
}

void	Phonebook::searchContact()
{
	std::string	input;
	int			input_number;

	if (numContacts == 0)
	{
		std::cout << "Phonebook is empty! No contacts to search." << std::endl;
		return;
	}

	while (1)
	{
		std::cout << "Please Enter the Contact ID (1-" << numContacts << "):";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return ;
		input_number = atoi(input.c_str());
		if (input_number <= 0 || input_number > numContacts)
			std::cout << "Error: Enter a valid contact number between 1 and " << numContacts << std::endl;
		else
			break;
	}
	displayContactCell(input_number);
}

void	Phonebook::displayContactCell(int index) 
{
	int arrayIndex = index - 1;
	
	if (arrayIndex >= 0 && arrayIndex < numContacts)
	{
		std::cout << "|----------|----------|----------|----------|----------|----------|" << std::endl;
		std::cout << "|"
		      << std::setw(10) << "Index" << "|"
		      << std::setw(10) << "First Name" << "|"
		      << std::setw(10) << "Last Name" << "|"
		      << std::setw(10) << "Nickname" << "|"
              << std::setw(10) << "Phone Numb" << "|"
              << std::setw(10) << "Darkest S." << "|" << std::endl;
		std::cout << "|----------|----------|----------|----------|----------|----------|" << std::endl;
		std::cout << "|"
		      << std::setw(10) << index << "|"
		      << formatField(contacts[arrayIndex].getFirstName()) << "|"
		      << formatField(contacts[arrayIndex].getLastName()) << "|"
		      << formatField(contacts[arrayIndex].getNickName()) << "|"
              << formatField(contacts[arrayIndex].getPhoneNumber()) << "|"
              << formatField(contacts[arrayIndex].getDarkestSecret()) << "|"
		      << std::endl;
	}
	else
	{
		std::cout << "Error: Invalid contact index!" << std::endl;
	}
}

void Phonebook::displayContacts() const
{
    if (numContacts == 0)
    {
        std::cout << "Phonebook is empty!" << std::endl;
        return;
    }

    std::cout << "|----------|----------|----------|----------|" << std::endl;
    std::cout << "|"
              << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;

    for (int i = 0; i < numContacts; i++)
    {
        std::cout << "|"
                  << std::setw(10) << (i + 1) << "|"
                  << formatField(contacts[i].getFirstName()) << "|"
                  << formatField(contacts[i].getLastName()) << "|"
                  << formatField(contacts[i].getNickName()) << "|"
                  << std::endl;
    }
    std::cout << "|----------|----------|----------|----------|" << std::endl;
}


