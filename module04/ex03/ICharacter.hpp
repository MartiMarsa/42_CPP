/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:00:43 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/03/17 15:00:45 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <string>
# include "AMateria.hpp"

class AMateria;

class ICharacter
{
	public:
		virtual std::string const & getName() const = 0;
		virtual 		~ICharacter() {}
		virtual void 	equip(AMateria* m) = 0;
		virtual void 	unequip(int idx) = 0;
		virtual void 	use(int idx, ICharacter& target) = 0;
		virtual void	printMaterias() const = 0;
};

#endif
