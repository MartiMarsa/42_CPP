/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:09:38 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/03/14 16:09:41 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; ++i)
        _ideas[i] = "Eat, reproduce, sleep, repeat.";
    std::cout << "A Brain has been created through a default constructor." << std::endl;
}

Brain::Brain(const Brain &other)
{
    for (int i = 0; i < 100; ++i)
        _ideas[i] = other._ideas[i];
    std::cout << "A Brain has been created trough a copy-constructor." << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
    if (this != &other)
    {
        for (int i = 0; i != 100; ++i)
            this->_ideas[i] = other._ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "A Brain has been removed through a default destructor." << std::endl;
}

void    Brain::setIdea(int index, const std::string &idea)
{
    if (index >= 0 && index <= 100)
        _ideas[index] = idea;
}

void    Brain::printIdeas() const
{
    for (int i = 0; i != 100; ++i)
        std::cout << _ideas[i] << std::endl;
}
