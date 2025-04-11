/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realType.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:56:33 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/04/11 14:56:36 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REALTYPE_HPP
# define REALTYPE_HPP

# include <string>
# include <cstdlib>
# include <iostream>
# include <typeinfo>

class Base
{
    public:
        virtual ~Base();
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base *	generate(void);
void    identify(Base * p);
void	identify(Base & p);

#endif
