/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:40:59 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/03/14 19:41:02 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(){}

AMateria::AMateria(const AMateria &other){}

AMateria	&AMateria::operator=(const AMateria &other) {}

AMateria::~AMateria(){}

std::string const &AMateria::getType() const {}

void	AMateria::use(ICharacter &target) {}

