/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:14:01 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/21 16:07:27 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void)
	: Form("RobotomyRequestForm", 72, 45), _target("") { std::cout
	<< BLUE << "Robotomy Request Form Default Constructor called" << std::endl; }

RobotomyRequestForm::~RobotomyRequestForm(void)
	{ std::cout << RED << "Robotomy Request Form Destructor called" << DEFAULT << std::endl; }

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: Form("RobotomyRequestForm", 72, 45), _target(target) { std::cout
	<< BLUE << "Robotomy Request Form Standard Constructor called" << DEFAULT << std::endl; }

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src)
	: Form("RobotomyRequestForm", 72, 45)
{
	std::cout << BLUE << "Robotomy Request Form Copy Constructor called" << DEFAULT << std::endl;
	if (this != &src)
		*this = src;
	return ;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	std::cout << "Can't copy anything" << std::endl;
	src.getTarget();
	std::cout << BLUE << "Robotomy Request Form Assignment Constructor called" << DEFAULT << std::endl;
	return (*this);
}

const std::string	&RobotomyRequestForm::getTarget(void) const { return (this->_target); }

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	this->checkExecutability(executor);
	std::cout << BLUE << "* Unbearable drilling noises *" << DEFAULT << std::endl;
	if (std::rand() % 2)
		std::cout << GREEN << "The Form of " << this->_target << " has been successfull"
			"y robotomized" << DEFAULT << std::endl;
	else
		std::cout << RED << "The robotomization on " << this->_target << " may or may "
			"not have been a complete and utter failure." << DEFAULT << std::endl;
}