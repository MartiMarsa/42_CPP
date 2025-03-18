/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:50:50 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/03/18 13:50:52 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main()
{
    AMateria*	ice = new Ice();
    AMateria*	ice1 = new Ice();
    AMateria*	ice2 = new Ice();
	AMateria*	ice3 = new Ice();
    AMateria*	cure = new Cure();
    AMateria*	cure2 = new Cure();
    AMateria*	cure3 = new Cure();					
    ICharacter*	pako = new Character("Paco");
	ICharacter* pedro = new Character("Pedro");

	pako->equip(ice);
	pako->equip(ice1);
	pako->equip(ice2);
	pako->equip(ice);
	pako->equip(cure);
	pako->equip(cure2);
	pako->equip(cure3);
	pedro->equip(ice3);
	pako->printMaterias();
	pedro->printMaterias();
	pako->use(0, *pedro);
	pedro->use(0, *pako);
	pako->use(3, *pako);
	pako->unequip(0);
	pako->unequip(0);
	pako->unequip(1);
	pako->unequip(2);
	pako->printMaterias();

	delete pako;
	delete pedro;
	return (0);
}
