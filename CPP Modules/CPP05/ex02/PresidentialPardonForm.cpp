/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:18:02 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/21 16:06:10 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) :
Form("PresidentialPardonForm", 25, 5), _target("")
{ std::cout << BLUE << "Presidential Pardon Form Default Constructor called"
<< std::endl; }

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
Form("PresidentialPardonForm", 25, 5), _target(target)
{ std::cout << BLUE << "Presidential Pardon Form Standard Constructor called"
<< std::endl; }

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src)
	: Form("RobotomyRequestForm", 25, 5)
{
	std::cout << BLUE << "Presidential Pardon Form Copy Constructor called" << DEFAULT << std::endl;
	if (this != &src)
		*this = src;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	std::cout << "Can't copy anything" << std::endl;
	src.getTarget();
	std::cout << BLUE << "Presidential Pardon Form Assignment Constructor called" << DEFAULT << std::endl;
	return (*this);
}

const std::string	&PresidentialPardonForm::getTarget(void) const { return (this->_target); }

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	this->checkExecutability(executor);
	std::cout << GREEN << "Presidential Pardon Form: " << this->getTarget() << " has been pardoned by Zaphod Beeblebrox"
	<< DEFAULT << std::endl << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{ std::cout << RED << "Presidential Pardon Form Destructor called" << DEFAULT << std::endl; }