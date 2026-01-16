/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 22:32:14 by alermi            #+#    #+#             */
/*   Updated: 2025/11/11 22:37:14 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef HARL
# define HARL

class Harl {

	private:

		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	
	public:
		
		void			complain(std::string level);
		
};

#endif
