/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 02:24:58 by alermi            #+#    #+#             */
/*   Updated: 2025/10/11 03:20:37 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main(void)
{
    std::cout << "start the sim" << std::endl;
    
    Zombie *zombieHeap;

    zombieHeap = newZombie("ZombieHeap");
    zombieHeap->announce();
    
    std::cout << "This point delete the heap_zombie" << std::endl;
    delete zombieHeap;
    
    std::cout << "This checkpoint stack zombie" << std::endl;
    randomChump("StackZombie");
    return (0);
}