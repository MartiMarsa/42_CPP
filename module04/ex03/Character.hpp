/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:35:35 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/03/17 16:35:37 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

# define BAG 4

class Character : public ICharacter
{
	private:
		std::string		_name;
		AMateria		*_slot[4];
		AMateria		**_floor;
		unsigned int	_floorCapacity;
		unsigned int	_floorIdx;
		void			addToFloor(AMateria &materia);
		void			clearFloor();
	public:
	    Character();
		Character(std::string name);
		Character(const Character &other);
		Character &operator=(const Character &other);
	    ~Character();

		std::string const & getName() const;

		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);
		void	printMaterias() const;
		void	incrementFloorCapacity(unsigned int increment);
		void	incrementFloorIdx();
		unsigned int getFloorCapacity() const;
		unsigned int getFloorIdx() const;
};

#endif
