/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:02:05 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/02/25 16:02:07 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <cstdlib>

class Zombie
{
	private:

		std::string	_name;

	public:

	    Zombie();
		Zombie( std::string name );
	    ~Zombie();

		void	announce();
		void    reName( std::string name);
};

Zombie* zombieHorde( int N, std::string name ); 

#endif

