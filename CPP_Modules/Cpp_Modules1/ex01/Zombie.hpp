/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 03:32:08 by alermi            #+#    #+#             */
/*   Updated: 2025/10/11 04:11:09 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    private:
        std::string name;        
    public:
        Zombie() {};
        Zombie(std::string zombie_name);
        ~Zombie();

        void    announce(void);
        void    setName(const std::string& horde_name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
