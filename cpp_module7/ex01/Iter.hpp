/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 15:18:25 by alermi            #+#    #+#             */
/*   Updated: 2026/07/14 16:02:18 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template <typename T, typename F, typename Len>
void	Iter(T *array, const Len size, F function)
{
	for	(Len i = 0; i < size; i++)
	{
		function(array[i], size);
	}
}
