/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:59:30 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/21 11:43:22 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name(""),
	_grade(this->LowestGrade) { std::cout << GREEN << "Bureacrat Default Constructor called"
	<< DEFAULT << std::endl; }

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	std::cout << GREEN << "Bureacrat Copy Constructor called" << DEFAULT << std::endl;
	if (this != &src)
		*this = src;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name),
	_grade(grade)
{
	checkGrade();
	std::cout << GREEN << "Bureaucrat Standard Constructor called" << DEFAULT << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << GREEN << "Bureaucrat Assignment Constructor called" << DEFAULT << std::endl;
	if (this != &src)
		this->_grade = src._grade;
	std::cout << "Name is const, so it can't be overwritten" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat(void) { std::cout << RED << "Bureaucrat Destructor called" << DEFAULT << std::endl; }

const std::string	Bureaucrat::getName() const { return (this->_name); }

int	Bureaucrat::getGrade() const { return (this->_grade); }

void	Bureaucrat::checkGrade() const
{
	int i = 0;
	this->_grade > this->LowestGrade ? throw Bureaucrat::GradeTooLowException() :
	this->_grade < this->HighestGrade ? throw Bureaucrat::GradeTooHighException() : i = 0;
}

void	Bureaucrat::incrementGrade(void)
{
	this->_grade--;
	checkGrade();
	std::cout << GREEN << "Grade incremented successfully from the Bureaucrat" << std::endl;
}

void	Bureaucrat::decrementGrade(void)
{
	this->_grade++;
	checkGrade();
	std::cout << YELLOW << "Grade decremented successfully from the Bureaucrat" << DEFAULT << std::endl;
}

void	Bureaucrat::signForm(Form &form) const
{
	form.beSigned(*this) == true ? std::cout << GREEN << this->_name << " signs form " << form.getName()
		<< DEFAULT << std::endl : std::cout << YELLOW << this->_name << " couldn't sign form " << form.getName()
		<< " because their grade is not high enough" << DEFAULT << std::endl;
}

void	Bureaucrat::signExec(Form &form) const
{
	form.beExec(*this) == true ? std::cout << GREEN << this->_name << " executes form " << form.getName()
		<< DEFAULT << std::endl : std::cout << YELLOW << this->_name << " couldn't execute form " << form.getName()
		<< " because their grade is not high enough" << DEFAULT << std::endl;
}

std::ostream	&operator<<(std::ostream &ostr, const Bureaucrat &src)
{
	ostr << BLUE << src.getName();
	ostr << BLUE << ", bureaucrat grade: " << src.getGrade() << DEFAULT << std::endl;
	return (ostr);
}