/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:35:30 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/04/15 16:35:31 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <string>
# include <iostream>
# include <algorithm>
# include <exception>

template <typename T>
int easyfind(const T & container, int num)
{
	typename T::const_iterator	it = std::find(container.begin(), container.end(), num);
	if (it != container.end())
	{
		return std::distance(container.begin(), it);
	}
	throw std::runtime_error("Value not found. ");
}

#endif
