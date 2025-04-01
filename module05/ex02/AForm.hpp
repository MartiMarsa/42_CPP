/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:12:05 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/03/26 15:12:06 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include <fstream>
# include "Bureaucrat.hpp"

# define TOP_GRADE 1
# define LAST_GRADE 150

class Bureaucrat;

class AForm
{
    private:
        std::string const		_name;
        const unsigned int		_gradeToSign;
        const unsigned int		_gradeToExecute;
		bool					_ratified;		
    public:
        AForm(std::string const name, const unsigned int _gradeToSign,
			const unsigned int _gradeToExecute);
        virtual ~AForm();
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);

        std::string const &					getName() const;		
        unsigned int		    			getGradeToSign() const;
		unsigned int		   				getGradeToExecute() const;
		bool								getSigned() const;
		virtual std::string const &			getTarget() const = 0;

        void                    			beSigned(const Bureaucrat &Bcrat);
        void								execute(Bureaucrat const & executor) const;
		virtual void						executeAction() const = 0;


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

        class AFormAlreadySigned : public std::exception
        {
            public:
                const char* what() const throw();
        };  
		
		class AFormNotSigned : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const AForm &form);

#endif