/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:59:30 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/21 11:13:25 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name(""),
	_grade(this->LowestGrade) { std::cout << "Bureacrat Default Constructor called"
	<< std::endl; }

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	std::cout << BLUE << "Bureacrat Copy Constructor called" << DEFAULT << std::endl;
	if (this != &src)
		*this = src;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name),
	_grade(grade) {checkGrade();
	std::cout << BLUE << "Bureaucrat Standard Constructor called" << DEFAULT << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << BLUE << "Bureaucrat Assignment Constructor called" << DEFAULT << std::endl;
	if (this != &src)
		this->_grade = src._grade;
	std::cout << YELLOW << "Name is const, so it can't be overwritten" << DEFAULT << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat(void) { std::cout << RED << "Destructor called" << DEFAULT << std::endl; }

const std::string	Bureaucrat::getName() const { return (this->_name); }

int	Bureaucrat::getGrade() const { return (this->_grade); }

void	Bureaucrat::checkGrade() const {int i = 0; this->_grade > this->LowestGrade ? throw Bureaucrat::GradeTooLowException() :
this->_grade < this->HighestGrade ? throw Bureaucrat::GradeTooHighException() : i = 0;
}

std::ostream	&operator<<(std::ostream &ostr, const Bureaucrat &src)
{
	ostr << YELLOW << src.getName();
	ostr << ", bureaucrat grade: " << src.getGrade() << DEFAULT << std::endl;
	return (ostr);
}

void	Bureaucrat::incrementGrade(void)
{
	this->_grade--;
	checkGrade();
	std::cout << GREEN << "Grade incremented successfully from the Bureaucrat" << DEFAULT << std::endl;
}

void	Bureaucrat::decrementGrade(void)
{
	this->_grade++;
	checkGrade();
	std::cout << GREEN << "Grade decremented successfully from the Bureaucrat" << DEFAULT << std::endl;
}