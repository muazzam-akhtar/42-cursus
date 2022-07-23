/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 02:34:07 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/21 11:48:47 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name(""), _signed(false), _gradeSigned(lowGrade), _gradeExec(lowGrade)
	{ std::cout << BLUE << "Form Default Constructor called" << DEFAULT << std::endl; }

Form::Form(const std::string &name, int gradeSigned, int gradeExec) : _name(name),
	_signed(false), _gradeSigned(gradeSigned), _gradeExec(gradeExec)
{
	checkGrade();
	std::cout << BLUE << "Form Standard Constructor called" << DEFAULT << std::endl;
}

Form::Form(const Form &src) : _name(src._name), _signed(src._signed),
	_gradeSigned(src._gradeSigned), _gradeExec(src._gradeExec)
{
	*this = src;
	std::cout << BLUE << "Form Copy Constructor called" << DEFAULT << std::endl;	
}

Form	&Form::operator=(const Form &src)
{
	if (this != &src)
	{
		this->_signed = src.isSigned();
		std::cout << BLUE << "Form Assignment Constructor called" << DEFAULT << std::endl;
	}
	std::cout << YELLOW << "Name is const, so it can't be overwritten" << std::endl;
	return (*this);
}

Form::~Form(void) { std::cout << RED << "Form Destructor called" << DEFAULT << std::endl; }

const std::string	&Form::getName(void) const { return (this->_name); }

int	Form::getGradeSigned(void) const { return (this->_gradeSigned); }

int	Form::getGradeExec(void) const { return (this->_gradeExec); }

bool	Form::isSigned(void) const { return (this->_signed); }

bool	Form::beSigned(const Bureaucrat &other)
{
	other.getGrade() < this->_gradeSigned ? this->_signed = true : this->_signed = false;
	return (this->_signed);
}

bool	Form::beExec(const Bureaucrat &other)
{
	bool	res;
	other.getGrade() < this->_gradeExec ? res = true : res = false;
	return (res);
}

void	Form::checkGrade(void)
{
	int	grades;
	grades = getGradeSigned();
	grades < this->highGrade ? throw Form::GradeTooHighException()
		: grades > this->lowGrade ? throw Form::GradeTooLowException()
		: grades = getGradeExec();
	grades < this->highGrade ? throw Form::GradeTooHighException()
		: grades > this->lowGrade ? throw Form::GradeTooLowException()
		: grades = 0;
}

void	Form::checkExecutability(const Bureaucrat &bur) const
{
	if (this->_signed == false || bur.getGrade() >= this->_gradeExec)
		throw Form::CantExecuteForm();
}

std::ostream	&operator<<(std::ostream &ostr, const Form &src)
{
	ostr << BLUE << src.getName();
	ostr << ", Form Grade Signed: " << src.getGradeSigned()
	<< ", Form Grade Exec: " << src.getGradeExec() << ", Form is Signed: "
	<< src.isSigned() << DEFAULT;
	return (ostr);
}
