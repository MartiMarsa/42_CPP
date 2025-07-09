/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:00:07 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/07/09 17:00:09 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:

		MutantStack() {}
		~MutantStack() {}
		MutantStack(const MutantStack &other) : std::stack<T>(other) {}
		MutantStack &operator=(const MutantStack &other) {
			if (this != &other)
			{
				this->std::stack<T>::operator=(other);
			}
			return *this;
		}

		typedef typename std::stack<T>::container_type::iterator				iterator;
		typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

		iterator					begin() {return this->c.begin();}
		iterator					end() {return this->c.end();}
		const_iterator				begin() const {return this->c.begin();}
		const_iterator				end() const {return this->c.end();}
		reverse_iterator			rbegin() {return this->c.rbegin();}
		reverse_iterator			rend() {return this->c.rend();}
		const_reverse_iterator		rbegin() const {return this->c.rbegin();}
		const_reverse_iterator		rend() const {return this->c.rend();}
};

#endif
