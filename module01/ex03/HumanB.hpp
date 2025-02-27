/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:38:12 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/02/26 16:38:13 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
    private:

		std::string	_name;
		Weapon		*_weaponType;

    public:

		HumanB(std::string name);
		~HumanB();
    

		void	attack();
		void	setWeapon(Weapon &type);
};

#endif
