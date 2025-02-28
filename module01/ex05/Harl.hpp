/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:21:13 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/02/28 09:21:14 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
    public:

		Harl();
		~Harl();
		
		void	complain( std::string level);

	private:

		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
};

#endif
