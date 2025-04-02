/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:12:05 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/03/26 15:12:06 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

# define TOP_GRADE 1
# define LAST_GRADE 150

class Bureaucrat;

class Form
{
    private:
        std::string const		_name;
        const unsigned int		_gradeToSign;
        const unsigned int		_gradeToExecute;
		bool					_ratified;		
    public:
        Form(std::string const name, const unsigned int gradeToSign,
			const unsigned int gradeToExecute);
        ~Form();
        Form(const Form &other);
        Form &operator=(const Form &other);

        std::string const &		getName() const;		
        unsigned int		    getGradeToSign() const;
		unsigned int		    getGradeToExecute() const;
		bool					getSigned() const;

        void                    beSigned(const Bureaucrat &Bcrat);

        class GradeTooHighException : public std::exception
        {
			public:
				const char* what() const throw();
        };

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

        class FormAlreadySigned : public std::exception
        {
            public:
                const char* what() const throw();
        };  
};

std::ostream	&operator<<(std::ostream &out, const Form &form);

#endif