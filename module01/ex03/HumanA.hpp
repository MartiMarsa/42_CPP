/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:37:42 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/02/26 16:37:44 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
    private:
        Weapon&		_weaponType;
        std::string	_name;

    public:
        HumanA(std::string name, Weapon& type);
        ~HumanA();

        void    attack();
};

#endif
