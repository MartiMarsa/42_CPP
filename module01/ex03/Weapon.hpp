/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:37:10 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/02/26 16:37:12 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>
# include <iomanip>

class Weapon
{
    private:

        std::string			_type;
    
	public:

        Weapon(std::string type);
        ~Weapon();

		const std::string&	getType();
		void				setType(std::string type);
};



#endif
