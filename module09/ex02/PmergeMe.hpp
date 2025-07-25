/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:46:04 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/07/24 15:46:06 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <set>
# include <sstream>

# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define RESET   "\033[0m"

class PmergeMe
{
	private:
		std::vector<int>		_vector;
		std::deque<int>		_deque;
		void	removeDuplicates(const std::vector<int> &vector);
		void	removeDuplicates(const std::deque<int> &vector);

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe    &operator=(const PmergeMe &other);

		void 	parseArgs(int argc, char **argv);
		void	doSorting();
};

bool	ft_isDigit(char c);
bool	ft_strToLL(const std::string & str, long long int & num);

#endif
