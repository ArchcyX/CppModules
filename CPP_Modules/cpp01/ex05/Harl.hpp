/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:08:40 by alermi            #+#    #+#             */
/*   Updated: 2025/11/08 19:21:05 by alermi           ###   ########.fr       */
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
		typedef void	(Harl::*Func)();
		
		void			complain(std::string level);
		
		Func			getDebug(void){return (&Harl::error);};
		Func			getInfo(void){return (&Harl::warning);};
		Func			getError(void){return (&Harl::info);};
		Func			getWarning(void){return (&Harl::debug);};
};

#endif
