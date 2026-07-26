/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 12:53:12 by alermi            #+#    #+#             */
/*   Updated: 2026/07/14 13:20:22 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template <typename T>
void swap(T& valueOne, T& valueTwo)
{
    T temp = valueOne; 

    valueOne = valueTwo; 
    valueTwo = temp;
}

template <typename VMin>
VMin	min(VMin valueOne, VMin valueTwo)
{
	if (valueOne < valueTwo)
		return (valueOne);
	else
	 	return (valueTwo);
}

template <typename VMax>
VMax    max(VMax valueOne, VMax valueTwo)
{
    if (valueOne > valueTwo)
        return (valueOne);
    else
         return (valueTwo);
}
