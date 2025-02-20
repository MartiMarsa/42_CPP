/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:55:42 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/02/18 19:55:44 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <cctype>
# include <iomanip>
# include <cstdlib>

class	Contact
{
	public:

			Contact();
			~Contact();

			void		setNew();
			std::string getFirstName() const;
			std::string getLastName() const;
			std::string getNickName() const;
			std::string getPhoneNumber() const;
			std::string getDarkestSecret() const;

	private:

			std::string	_firstName;
			std::string	_lastName;
			std::string _nickName;
			std::string	_phoneNumber;
			std::string	_darkestSecret;

			std::string _readInput(std::string message) const;
			std::string _readPhone(std::string message) const;
			bool		_checkDigits(const std::string &str)  const;
};

#endif
