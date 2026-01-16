/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 03:31:54 by alermi            #+#    #+#             */
/*   Updated: 2025/10/11 04:24:48 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie  *zombieHorde;

    zombieHorde = new Zombie[N];
    for (int i = 0; i < N; ++i)
    {
        zombieHorde[i].setName(name);
    }
	return (zombieHorde);
}
