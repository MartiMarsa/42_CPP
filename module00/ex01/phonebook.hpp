/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:34:15 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/02/18 19:34:17 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <cctype>
# include <iomanip>
# include <cstdlib>
# include <string>
# include "contact.hpp"

class PhoneBook
{
    public:

        PhoneBook();
        ~PhoneBook();

        void    addContact();
        void    searchContact() const;
        void    displayContact() const;

    private:

		Contact _contactlist[8];
		int		_index;
};

#endif
