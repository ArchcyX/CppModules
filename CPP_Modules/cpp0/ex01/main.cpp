/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:00:12 by alermi            #+#    #+#             */
/*   Updated: 2025/09/06 19:56:37 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <cstdlib>
#include <string.h>

int controller(const std::string &input, const std::string &type)
{
    if (input.length() != type.length())
        return (0);

    for (size_t i = 0; i < input.length(); i++)
    {
        if (std::tolower(input[i]) != std::tolower(type[i]))
            return (0);
    }
    return (1);
}

std::string getInput(std::string outputText)
{
	std::string input;

	std::cout << std::endl;
	std::cout << outputText;
	while (1)
	{
		std::getline(std::cin, input);
		if (std::cin.eof())
			break;
		if (!input.empty())
			break ;
	}
	return (input);
}

Contact createContact()
{
	Contact newContact;
	std::string input;

	newContact.setFirstName(getInput("Enter First Name:"));
	newContact.setLastName(getInput("Enter Last Name:"));
	newContact.setNickName(getInput("Enter Nickname: "));
	newContact.setPhoneNumber(getInput("Enter Phone Number: "));
	newContact.setDarkestSecret(getInput("Enter Darkest Secret: "));
	return (newContact);
}

void	printMonitor(void)
{
	std::cout << "PLEASE SELECT AND OPTION" << std::endl << "-----------------------------" << std::endl;
	std::cout << "-> (ADD) : To add a new contact" << std::endl;
	std::cout << "-> (SEARCH) : To search for a contact" << std::endl;
	std::cout << "-> (EXIT) : To exit the application" << std::endl << "-----------------------------" << std::endl;
}

int	main(void)
{
	Phonebook	phonebook;
	Contact		contact;
	std::string	input;

	std::system("clear");
	std::cout << "Welcome to the Phonebook App" << std::endl;
	while (1)
	{
		printMonitor();
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "EOF detected" << std::endl;
			break ;
		}
		if (controller(input, "ADD"))
		{
			phonebook.addContact(createContact());
			std::cout << "" << std::endl;
			std::system("clear");
			phonebook.displayContacts();
		}
		else if (controller(input, "SEARCH"))
		{
				phonebook.searchContact();
				std::cout << "" << std::endl;
		}
		else if (controller(input, "EXIT"))
			break ;
		else {
			
			std::system("clear");
			phonebook.displayContacts();
			std::cout << "Invalid option. Please try again." << std::endl << std::endl;
		}
	}
	std::cout << "Exiting the Phonebook App. Thank for using" << std::endl;
	return (0);
}
