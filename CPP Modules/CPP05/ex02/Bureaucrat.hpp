/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:56:42 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/21 15:00:26 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <string>
# include <iomanip>
# include <exception>
# define RED "\001\033[1;91m\002"
# define GREEN "\001\033[1;92m\002"
# define DEFAULT "\001\033[0;39m\002"
# define YELLOW "\001\033[1;93m\002"
# define BROWN "\001\033[1;40m\002"
# define BLUE "\001\033[1;94m\002"
# include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat	&operator=(const Bureaucrat &src);
		Bureaucrat(const std::string &name, int grade);
		~Bureaucrat(void);
		const std::string	getName(void) const;
		void	incrementGrade(void);
		void	decrementGrade(void);
		int	getGrade(void) const;
		void	checkGrade(void) const;
		void	signForm(Form &form) const;
		bool	executeForm(Form const & form) const;
		// static bool	termination;
	private:
		const std::string	_name;
		int					_grade;
		static const int	HighestGrade = 1;
		static const int	LowestGrade = 150;
	public:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Bureaucrat: The Grade is too High");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Bureaucrat: The Grade is too Low");
				}
		};
};

std::ostream	&operator<<(std::ostream &ostr, const Bureaucrat &src);

#endif