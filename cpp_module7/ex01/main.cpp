/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 15:18:29 by alermi            #+#    #+#             */
/*   Updated: 2026/07/14 15:18:30 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Iter.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

int main(void)
{
    std::cout << BOLD << CYAN << "\n========================================" << RESET << std::endl;
    std::cout << BOLD << CYAN << "       EX01: ITER FUNCTION TESTS        " << RESET << std::endl;
    std::cout << BOLD << CYAN << "========================================" << RESET << std::endl;

    std::cout << BOLD << YELLOW << "\n[BLOCK 1] Non-Const Array Tests (Multiplexer Active)" << RESET << std::endl;
    {
        int     arr[] = {97, 98, 99};
        double  arr1[] = {97, 98, 99};
        char    arr2[] = {97, 98, 99};

        std::cout << BLUE << "-> Int Array (Original x2): " << RESET << std::endl;
        Iter(arr, 3, multiplexer<int>);
        Iter(arr, 3, ftPrintArr<int>);

        std::cout << BLUE << "-> Double Array (Original x2): " << RESET << std::endl;
        Iter(arr1, 3, multiplexer<double>);
        Iter(arr1, 3, ftPrintArr<double>);

        std::cout << BLUE << "-> Char Array (Original +1): " << RESET << std::endl;
        Iter(arr2, 3, multiplexer<char>);
        Iter(arr2, 3, ftPrintArr<char>);
    }

    std::cout << BOLD << YELLOW << "\n[BLOCK 2] Const Array Tests (Read-Only / Print)" << RESET << std::endl;
    {
        const int       arr[] = {97, 98, 99};
        const double    arr1[] = {97, 98, 99};
        const char      arr2[] = {97, 98, 99};

        std::cout << GREEN << "-> Const Int Array Print: " << RESET << std::endl;
        Iter(arr, 3, ftPrintArr<int>);

        std::cout << GREEN << "-> Const Double Array Print: " << RESET << std::endl;
        Iter(arr1, 3, ftPrintArr<double>);

        std::cout << GREEN << "-> Const Char Array Print: " << RESET << std::endl;
        Iter(arr2, 3, ftPrintArr<char>);
    }

    std::cout << BOLD << CYAN << "\n========================================" << RESET << std::endl;
    return (0);
}
