/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:12:05 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/03/26 15:12:06 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Form.hpp"

# define TOP_GRADE 1
# define LAST_GRADE 150

# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define RESET   "\033[0m"

class Form;

class Bureaucrat
{
    private:
        std::string const     _name;
        unsigned int            _grade;
    public:
        Bureaucrat(std::string const name, unsigned int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);

        std::string const &     getName() const;		
        unsigned int    getGrade() const;

        void                    upGrade();
		void					downGrade();

        void                    signForm(Form &form);

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
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &Bcrat);

#endif