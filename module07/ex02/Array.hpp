/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:10:31 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/04/14 16:10:33 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <string>
# include <iostream>

template<typename T>
class Array
{
	private:
		T*				_element;
		unsigned int	_len;
	public:
		Array();
		~Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array &operator=(const Array &other);

		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		unsigned int	size(void) const;
};

# include "Array.tpp"

#endif