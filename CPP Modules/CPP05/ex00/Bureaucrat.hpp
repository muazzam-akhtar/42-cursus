/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:56:42 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/21 11:03:35 by makhtar          ###   ########.fr       */
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
# define BLUE "\001\033[1;94m\002"

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
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("\001\033[1;91m\002The Grade is too High\001\033[0;39m\002");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("\001\033[1;91m\002The Grade is too Low\001\033[0;39m\002");
				}
		};
	private:
		const std::string	_name;
		int					_grade;
		static const int	HighestGrade = 1;
		static const int	LowestGrade = 150;
};

std::ostream	&operator<<(std::ostream &ostr, const Bureaucrat &src);

#endif