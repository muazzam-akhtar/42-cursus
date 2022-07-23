/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 19:35:26 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/22 11:33:13 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) { std::cout << BLUE << "Intern Constructor called" << DEFAULT << std::endl; }

Intern::Intern(const Intern &src)
{
	std::cout << BLUE << "Intern Copy Constructor called" << DEFAULT << std::endl;
	*this = src;	
}

Intern	&Intern::operator=(const Intern &src)
{
	(void)src;
	std::cout << BLUE << "Intern Assignment Constructor called" << DEFAULT << std::endl;
	return (*this);
}

static Form	*newPresident(const std::string target)
{
	Form	*obj = new PresidentialPardonForm(target);
	return (obj);
}

static Form	*newRobo(const std::string target)
{
	Form	*obj = new RobotomyRequestForm(target);
	return (obj);
}

static Form	*newShrub(const std::string target)
{
	Form	*obj = new ShrubberyCreationForm(target);
	return (obj);
}

Form	*Intern::makeForm(const std::string &formName, const std::string &target) const
{
	Form	*result = NULL;
	std::string	types[] = {"Presidential Pardon Form", "Robotomy Request Form", "Shrubbery Creation Form", ""};
	Form	*(*objs[3])(std::string trgt) = {newPresident, newRobo, newShrub};
	for (int i = 0; types[i] != ""; i++)
	{
		if (formName == types[i])
		{
			result = objs[i](target);
			break;
		}
	}
	result == NULL ? std::cout << RED << "Intern did not find the form "
	<< formName << DEFAULT << std::endl << std::endl : std::cout << std::endl << GREEN << "Intern creates form-"
	<< formName << DEFAULT << std::endl;
	return (result);
}

Intern::~Intern(void) { std::cout << RED << "Intern Destructor called" << DEFAULT << std::endl; }

std::ostream &	operator<<( std::ostream & ostr, Intern const & src)
{
	(void)src;
	ostr << "Intern" << std::endl;
	return ostr;
}