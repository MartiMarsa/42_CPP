\
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:25:37 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/03/05 19:25:40 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <string>
# include <iostream>

class ClapTrap
{
    private:

        std::string _name;
        int         _hitPoints;
        int         _energyPoints;
        int         _attackDamage;

    public:

		ClapTrap();
        ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
        ~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount)
};

#endif
