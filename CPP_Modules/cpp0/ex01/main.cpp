/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:13:37 by alermi            #+#    #+#             */
/*   Updated: 2025/09/05 17:19:28 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp
#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>
#include <string>

int	main()
{
	
	PhoneBook phonebook;
	std::string command;

	std::cout << "📞 80'ler Tarzı Telefon Rehberi'ne Hoşgeldin!\n";

	while (true) {
		std::cout << "\nKomut gir (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);

		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH") {
		    phonebook.searchContacts();
				
		    std::cout << "Detayını görmek istediğin indeks: ";
		    std::string input;
		    std::getline(std::cin, input);
		    int index = -1;
				
		    std::stringstream ss(input);
		    if (!(ss >> index)) {
		        std::cout << "❌ Geçerli bir sayı girin!\n";
		        continue;
		    }
		    phonebook.showContactDetails(index);
		}
		else if (command == "EXIT") {
			std::cout << "Görüşmek üzere! 👋\n";
			break;
		}
		else {
			std::cout << "Bilinmeyen komut. Sadece ADD, SEARCH, EXIT geçerli.\n";
		}
	}
	return (0);
}
