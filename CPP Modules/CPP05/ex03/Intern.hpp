/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 19:18:33 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/22 10:45:01 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &src);
		~Intern(void);
		Intern	&operator=(const Intern &rhs);
		Form	*makeForm(const std::string &formName, const std::string &type) const;
};

std::ostream	&operator<<( std::ostream &ostr, const Intern &src );

#endif