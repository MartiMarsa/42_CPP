/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:44:09 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/04/16 16:44:11 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <string>
# include <iostream>
# include <vector>
# include <exception>
# include <algorithm>
# include <climits>

class Span
{
	private:
		unsigned int		_N;
		std::vector<int>	_numbers;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void						addNumber(int num);
		int							shortestSpan();
		int							longestSpan();
		const std::vector<int> &	getNumbers() const;
		int							getNumberAt(int index) const;
};

#endif

