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
Array<T>::Array(unsigned int n) : _element(new T[n]()), _len(n) {}

template<typename T>
Array<T>::Array(const Array &other) : _element(NULL), _len(other._len)
{
	if (this->_len)
	{
		_element = new T[_len];
		for (unsigned int i = 0; i < this->_len; ++i)
			this->_element[i] = other._element[i];
	}
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this ==  &other)
		return *this;
	delete [] this->_element;
	this->_element = NULL;
	this->_len = other._len;
	if (this->_len)
		this->_element = new T[_len];
	for (unsigned int i = 0; i < this->_len; ++i)
		this->_element[i] = other._element[i];
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

template<typename T>
T*	Array<T>::getRawPointer() const
{
	return (this->_element);
}
