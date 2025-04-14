/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:55:21 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/04/14 13:55:23 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <string>
# include <iostream>
# 

template <typename T>
void	hello(T a)
{
	std::cout << "Member of array " << a << " says hello!" << std::endl; 
}

template <typename T>
void	iter(T* array, size_t len, void (*f)(const T &))
{
	for (size_t i = 0; i != len; ++i)
	{
		f(array[i]);
	}
}

#endif

