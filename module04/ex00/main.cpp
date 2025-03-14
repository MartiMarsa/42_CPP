/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:56:30 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/03/14 15:56:31 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* k = new WrongAnimal();
    const WrongAnimal* l = new WrongCat();

    std::cout << meta->getType() << std::endl;
    meta->makeSound(); // Will output the sound of an Animal

    std::cout << j->getType() << std::endl;
    j->makeSound(); // Will output the sound of a Dog

    std::cout << i->getType() << std::endl;
    i->makeSound(); // Will output the sound of a Cat

    std::cout << k->getType() << std::endl;
    k->makeSound(); // Will output the sound of a WrongAnimal

    std::cout << l->getType() << std::endl;
    l->makeSound(); // Will output the sound of a WrongAnimal  
    static_cast<const WrongCat*>(l)->makeSound(); // Will output the sound of a WrongCat

    delete meta;
    delete j;
    delete i;
    delete k;
    delete l;
    return 0;
}
