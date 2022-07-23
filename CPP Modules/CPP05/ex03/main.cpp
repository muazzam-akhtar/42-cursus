/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 02:14:22 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/22 11:37:31 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Bureaucrat.hpp"
// #include "Form.hpp"

// int main(void)
// {
// 	{try
// 	{
// 		Bureaucrat	file("Muazzam", 4);
// 		std::cout << file;
// 		file.incrementGrade();
// 		std::cout << file;
// 		file.incrementGrade();
// 		std::cout << file;
// 		file.incrementGrade();
// 		std::cout << file;
// 		file.incrementGrade();
// 		std::cout << file;
// 		/* code */
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << RED << e.what() << DEFAULT << '\n';
// 	}}
// 	{
// 		try
// 		{
// 			Form	tmp("Muazzam", 45, 151);
// 			std::cout << tmp << std::endl;
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << RED << e.what() << DEFAULT << '\n';
// 		}
// 	}
// 	return (0);
// }

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
// #include "Form.hpp"

int	main(void)
{
	std::srand(std::time(NULL));
	// Form			*form = NULL;
	// Bureaucrat		bob("bob", 1);
	// Bureaucrat		phil("phil", 40);
	// Bureaucrat		luc("luc", 150);

	// std::cout << luc << std::endl;
	// try
	// {
	// 	form = new ShrubberyCreationForm("28C");
	// 	// std::cout<< form->getGradeExec()<<std::endl;
	// 	form->beSigned(bob);
	// 	form->execute(phil);
	// 	// form->execute(luc);
	// 	delete form;
	// 	form = NULL;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	// try
	// {
	// 	form = new RobotomyRequestForm("28B");
	// 	form->beSigned(bob);
	// 	// form->execute(luc);
	// 	form->execute(phil);
	// 	form->execute(phil);
	// 	form->execute(phil);
	// 	form->execute(phil);
	// 	form->execute(phil);
	// 	form->execute(phil);
	// 	form->execute(phil);
	// 	form->execute(phil);
	// 	delete form;
	// 	form = NULL;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	// try
	// {
	// 	form = new PresidentialPardonForm("28Z");
	// 	form->execute(bob);
	// 	delete form;
	// 	form = NULL;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }

	// try
	// {
	// 	form = new PresidentialPardonForm("28A");
	// 	form->beSigned(bob);
	// 	form->execute(bob);
	// 	delete form;
	// 	form = NULL;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	Intern		usefulIdiot;
	Bureaucrat	paul("Paul", 137);
	Form		*form;
	form = usefulIdiot.makeForm("Shrubbery Creation Form", "Justin");
	form->beSigned(paul);
	try
	{
		form->execute(paul);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	if (form)
		delete form;
	Bureaucrat	john("John", 4);
	form = usefulIdiot.makeForm("Presidential Pardon Form", "John");
	if (form)
		delete form;
	Bureaucrat	jan("Jan", 140);
	form = usefulIdiot.makeForm("Robotomy Request Form", "Jan");
	if (form)
		delete form;
	try
	{
		/* code */
		Bureaucrat	Mike("Mike", 200);
		form = usefulIdiot.makeForm("Robotomy Request Form", "Jan");
		if (form)
			delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		/* code */
		Bureaucrat	Ken("Ken", 1);
		form = usefulIdiot.makeForm("Robotomy1 Request Form", "Jan");
		if (form)
			delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}