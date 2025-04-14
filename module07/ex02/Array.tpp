/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:10:31 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/04/14 16:10:33 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array() : _element(NULL), _len(0) {}

template<typename T>
Array<T>::~Array()
{
	delete[] _element;
}

template<typename T>
void initializeArray(T* arr, unsigned int n)
{
	for (unsigned int i = 0; i < n; ++i)
		_element[i] = NULL;
}

template<typename T>
void initializeArray(T& arr, unsigned int n) {}

template<typename T>
Array<T>::Array(unsigned int n) : _element(new T[n]()), _len(n)\
{
	initializeArray(this->_element, this->_len);
}

template<typename T>
Array<T>::Array(const Array &other)
{
	if (this != &other)
	{	
		for (unsigned int i = 0; i < n; ++i)
			this->_element[i] = other._element;
	}
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{	
		for (unsigned int i = 0; i < n; ++i)
			this->_element[i] = other._element;
	}
	return (*this);
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= this->_len)
		throw std::out_of_range("Index out of range.");
	return (this->_element[index]);
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= this->_len)
		throw std::out_of_range("Index out of range.");
	return (this->_element[index]);
}

template<typename T>
unsigned int	Array<T>::size(void) const
{
	return this->_len;
}
