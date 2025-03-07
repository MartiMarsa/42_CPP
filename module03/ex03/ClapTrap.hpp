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

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define RESET "\033[0m"

# include <string>
# include <iostream>

class ClapTrap
{
    protected:

        std::string			_name;
        unsigned int		_hitPoints;
        unsigned int		_energyPoints;
        unsigned int		_attackDamage;

    public:

		ClapTrap();
        ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
        virtual ~ClapTrap();

		std::string		getName();
		unsigned int	getHitPoints();
		unsigned int	getEnergyPoints();
		unsigned int	getAttackDamage();

		void	setEnergyPoints(int energyPoints);
		void	sethitPoints(int hitPoints);
		void	setName(std::string name);
		void	setAttackDamage(int attackDamage);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		virtual void	attack(const std::string& target);
};

#endif
