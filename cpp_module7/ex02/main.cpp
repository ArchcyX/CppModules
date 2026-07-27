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


#include "./Array.tpp"
#include <iostream>
#include <string>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

int main(void)
{
    std::cout << BOLD << CYAN << "\n=================================================" << RESET << std::endl;
    std::cout << BOLD << CYAN << "           EX02: ARRAY CLASS MONITORING          " << RESET << std::endl;
    std::cout << BOLD << CYAN << "=================================================\n" << RESET << std::endl;

    std::cout << BOLD << YELLOW << "[TEST 1] Empty Array Creation" << RESET << std::endl;
    try {
        Array<int> emptyArr;
        std::cout << GREEN << "Empty array created. Size: " << emptyArr.size() << RESET << std::endl;

        std::cout << BLUE << "Trying to access emptyArr[0]... " << RESET << std::endl;
        std::cout << emptyArr[0] << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD << YELLOW << "\n[TEST 2] Parameterized Array & Default Init (int)" << RESET << std::endl;
    Array<int> numArr(5);
    std::cout << GREEN << "numArr created with size: " << numArr.size() << RESET << std::endl;
    std::cout << BLUE << "Initial values (should be 0): " << RESET;
    for (unsigned int i = 0; i < numArr.size(); i++) {
        std::cout << numArr[i] << " ";
    }
    std::cout << std::endl;


    std::cout << BOLD << YELLOW << "\n[TEST 3] Value Assignment & Copy Constructor (Deep Copy)" << RESET << std::endl;
    for (unsigned int i = 0; i < numArr.size(); i++) {
        numArr[i] = (i + 1) * 10;
    }
    
    Array<int> copyArr(numArr);
    std::cout << GREEN << "copyArr created via copy constructor." << RESET << std::endl;
    
    copyArr[0] = 999;
    copyArr[4] = 999;

    std::cout << BLUE << "Original numArr : " << RESET;
    for (unsigned int i = 0; i < numArr.size(); i++) std::cout << numArr[i] << " ";
    std::cout << BLUE << "\nModified copyArr: " << RESET;
    for (unsigned int i = 0; i < copyArr.size(); i++) std::cout << copyArr[i] << " ";
    std::cout << std::endl;


    std::cout << BOLD << YELLOW << "\n[TEST 4] Assignment Operator (=)" << RESET << std::endl;
    Array<int> assignArr(2);
    assignArr = numArr;

    std::cout << GREEN << "assignArr size after assignment: " << assignArr.size() << RESET << std::endl;
    assignArr[2] = 777;

    std::cout << BLUE << "Original numArr : " << RESET;
    for (unsigned int i = 0; i < numArr.size(); i++) std::cout << numArr[i] << " ";
    std::cout << BLUE << "\nModified assignArr: " << RESET;
    for (unsigned int i = 0; i < assignArr.size(); i++) std::cout << assignArr[i] << " ";
    std::cout << std::endl;


    std::cout << BOLD << YELLOW << "\n[TEST 5] Out of Bounds Monitoring" << RESET << std::endl;
    try {
        std::cout << BLUE << "Trying to access numArr[5] (size is 5, max index is 4)... " << RESET << std::endl;
        std::cout << numArr[5] << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD << YELLOW << "\n[TEST 7] Complex Types (std::string)" << RESET << std::endl;
    Array<std::string> strArr(3);
    strArr[0] = "Hello";
    strArr[1] = "42";
    strArr[2] = "School";

    std::cout << GREEN << "String Array contents: " << RESET;
    for (unsigned int i = 0; i < strArr.size(); i++) {
        std::cout << strArr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << BOLD << CYAN << "\n=================================================" << RESET << std::endl;
    std::cout << BOLD << CYAN << "             TESTING COMPLETED SUCCESSFULLY      " << RESET << std::endl;
    std::cout << BOLD << CYAN << "=================================================\n" << RESET << std::endl;

    return 0;
}
