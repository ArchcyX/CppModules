/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:16:20 by alermi            #+#    #+#             */
/*   Updated: 2026/07/27 20:11:16 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main()
{
    // ==========================================
    // 1. VECTOR (Dynamic Array) TEST
    // ==========================================
    std::cout << "--- 1. std::vector Test ---" << std::endl;
    std::vector<int> myVector;
    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);

    try
    {
        std::vector<int>::iterator itVec = easyfind(myVector, 20);
        std::cout << "[Success] Found in Vector: " << *itVec << std::endl;

        std::cout << "[Attempt] Searching for 99 in Vector..." << std::endl;
        easyfind(myVector, 99);
    }
    catch(const std::exception& e)
    {
        std::cerr << "[ERROR] " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // ==========================================
    // 2. LIST (Doubly Linked List) TEST
    // ==========================================
    std::cout << "--- 2. std::list Test ---" << std::endl;
    std::list<int> myList;
    myList.push_back(100);
    myList.push_back(200);
    myList.push_back(300);

    try
    {
        std::list<int>::iterator itList = easyfind(myList, 300);
        std::cout << "[Success] Found in List: " << *itList << std::endl;

        std::cout << "[Attempt] Searching for 999 in List..." << std::endl;
        easyfind(myList, 999);
    }
    catch(const std::exception& e)
    {
        std::cerr << "[ERROR] " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // ==========================================
    // 3. DEQUE (Double-Ended Queue) TEST
    // ==========================================
    std::cout << "--- 3. std::deque Test ---" << std::endl;
    std::deque<int> myDeque;
    myDeque.push_back(1000);
    myDeque.push_back(2000);
    myDeque.push_back(3000);

    try
    {
        std::deque<int>::iterator itDeque = easyfind(myDeque, 1000);
        std::cout << "[Success] Found in Deque: " << *itDeque << std::endl;

        std::cout << "[Attempt] Searching for 42 in Deque..." << std::endl;
        easyfind(myDeque, 42);
	}
    catch(const std::exception& e)
    {
        std::cerr << "[ERROR] " << e.what() << std::endl;
    }

    return 0;
}
