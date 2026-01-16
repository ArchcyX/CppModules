/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 20:57:46 by alermi            #+#    #+#             */
/*   Updated: 2026/01/11 21:23:14 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	protected:

			std::string		_name;
			unsigned int	_hitPoints;
			unsigned int	_energyPoints;
			unsigned int	_attackDamage;
	public:
			ClapTrap();
			virtual ~ClapTrap();
			ClapTrap(std::string name);
			ClapTrap(const ClapTrap &variant);
			ClapTrap &operator=(const ClapTrap &other);

			void	attack(const std::string &target);
			void	takeDamage(unsigned int value);
			void	beRepaired(unsigned int value);
};

#endif
