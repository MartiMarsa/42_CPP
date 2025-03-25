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
	AMateria*	ice4 = new Ice();
	AMateria*	ice5 = new Ice();
	AMateria*	ice6 = new Ice();
    AMateria*	cure = new Cure();
    AMateria*	cure2 = new Cure();
    AMateria*	cure3 = new Cure();
	AMateria*	cure4 = new Cure();					
    Character*	pako = new Character("Paco");
	Character* pedro = new Character("Pedro");

	pako->equip(cure2);
	pako->equip(ice);
	pako->equip(ice);
	pako->equip(ice1);
	pako->equip(ice2);
	pako->equip(ice3);
	pako->equip(ice4);
	pako->equip(ice5);
	pako->equip(ice6);
	pako->equip(cure3);
	std::cout << std::endl;
	pako->printMaterias();
	pedro->printMaterias();
	std::cout << std::endl;
	pako->use(3, *pedro);
	pako->use(0, *pedro);
	pedro->use(0, *pako);
	std::cout << std::endl;
	pako->unequip(0);
	pako->unequip(0);
	pako->unequip(1);
	pako->unequip(2);
	pako->equip(cure4);
	std::cout << std::endl;
	pedro->equip(cure);
	pedro->printMaterias();
	pedro->unequip(0);
	pedro->printMaterias();
	std::cout << std::endl;
	pako->printMaterias();
	std::cout << std::endl;
	Character* jotapako = new Character(*pako);
	jotapako = pako;
	jotapako->printMaterias();
	delete pako;
	delete pedro;
	// delete jotapako;
	return (0);
}
