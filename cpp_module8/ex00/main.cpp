/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:16:20 by alermi            #+#    #+#             */
/*   Updated: 2026/07/27 20:47:09 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"

int main()
{
    // ==========================================
    // 1. VECTOR (Dynamic Array) TEST
    // ==========================================
    std::cout << CYAN << "--- 1. std::vector Test ---" << RESET << std::endl;
    std::vector<int> myVector;
    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);

    try
    {
        std::vector<int>::iterator itVec = easyfind(myVector, 20);
        std::cout << GREEN << "[Success] Found in Vector: " << *itVec << RESET << std::endl;

        std::cout << YELLOW << "[Attempt] Searching for 99 in Vector..." << RESET << std::endl;
        easyfind(myVector, 99);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "[ERROR] " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // ==========================================
    // 2. LIST (Doubly Linked List) TEST
    // ==========================================
    std::cout << CYAN << "--- 2. std::list Test ---" << RESET << std::endl;
    std::list<int> myList;
    myList.push_back(100);
    myList.push_back(200);
    myList.push_back(300);

    try
    {
        std::list<int>::iterator itList = easyfind(myList, 300);
        std::cout << GREEN << "[Success] Found in List: " << *itList << RESET << std::endl;

        std::cout << YELLOW << "[Attempt] Searching for 999 in List..." << RESET << std::endl;
        easyfind(myList, 999);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "[ERROR] " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // ==========================================
    // 3. DEQUE (Double-Ended Queue) TEST
    // ==========================================
    std::cout << CYAN << "--- 3. std::deque Test ---" << RESET << std::endl;
    std::deque<int> myDeque;
    myDeque.push_back(1000);
    myDeque.push_back(2000);
    myDeque.push_back(3000);

    try
    {
        std::deque<int>::iterator itDeque = easyfind(myDeque, 1000);
        std::cout << GREEN << "[Success] Found in Deque: " << *itDeque << RESET << std::endl;

        std::cout << YELLOW << "[Attempt] Searching for 42 in Deque..." << RESET << std::endl;
        easyfind(myDeque, 42);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "[ERROR] " << e.what() << RESET << std::endl;
    }

    return 0;
}
