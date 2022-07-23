/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 02:14:22 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/21 16:09:15 by makhtar          ###   ########.fr       */
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
#include <ctime>
#include <cstdlib>
// #include "Form.hpp"

int	main(void)
{
	std::srand(std::time(NULL));
	Form			*form = NULL;
	Bureaucrat		bob("bob", 149);
	Bureaucrat		phil("phil", 40);
	Bureaucrat		luc("luc", 44);

	// try
	// {
	// 	form = new ShrubberyCreationForm("28C");
	// 	form->beSigned(bob);
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
	// 	form = new RobotomyRequestForm("28B");
	// 	form->beSigned(bob);
	// 	form->execute(bob);
	// 	form->execute(luc);
	// 	form->execute(luc);
	// 	form->execute(luc);
	// 	form->execute(luc);
	// 	form->execute(luc);
	// 	form->execute(luc);
	// 	form->execute(luc);
	// 	form->execute(luc);
	// 	form->execute(luc);
	// 	delete form;
	// 	form = NULL;
	// }
	// catch (std::exception &e)
	// {
	// 	delete form;
	// 	std::cout << e.what() << std::endl;
	// }
	// try
	// {
	// 	form = new RobotomyRequestForm("28B");
	// 	form->beSigned(bob);
	// 	form->execute(bob);
	// 	form->execute(luc);
	// 	form->execute(luc);
	// 	form->execute(luc);
	// 	form->execute(luc);
	// 	form->execute(luc);
	// 	form->execute(luc);
	// 	form->execute(luc);
	// 	form->execute(luc);
	// 	form->execute(luc);
	// 	delete form;
	// 	form = NULL;
	// }
	// catch (std::exception &e)
	// {
	// 	delete form;
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
	try
	{
		form = new PresidentialPardonForm("28A");
		// form->beSigned(bob);
		form->beSigned(bob);
		// form->execute(bob);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		delete form;
		std::cout << e.what() << std::endl;
	}
	return 0;
}