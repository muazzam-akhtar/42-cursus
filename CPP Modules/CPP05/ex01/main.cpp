/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 02:14:22 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/21 11:48:06 by makhtar          ###   ########.fr       */
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
#include "Form.hpp"

int	main(void)
{
	try
	{
		Form	f("EB110", 0, 1);
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << DEFAULT << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Form	f("EB110", 1, 0);
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << DEFAULT << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Form	f("EB110", 0, 0);
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << DEFAULT << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Form	f("EB110", 150, 151);
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << DEFAULT << std::endl;
	}
	std::cout << std::endl;
	
	try
	{
		Form	f("EB110", 151, 150);
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << DEFAULT << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Form	f("EB110", 1, 1);
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << DEFAULT << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Form	f("EB110", 150, 150);
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << DEFAULT << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Form	f("EB110", 100, 100);
		Bureaucrat	trial("Bassam", 99);	
		std::cout << f.beSigned(trial) << std::endl;
		trial.signForm(f);
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << DEFAULT << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Form	f("EB110", 100, 100);
		Bureaucrat	trial("Bassam", 101);	
		std::cout << f.beSigned(trial) << std::endl;
		trial.signForm(f);
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << DEFAULT << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Form	f("EB110", 100, 100);
		Bureaucrat	trial("Bassam", 90);
		Bureaucrat	test("Muazzam", 99);
		std::cout << f << std::endl;
		std::cout << f.beSigned(trial) << std::endl;
		trial.signExec(f);
		std::cout << f << std::endl;
		trial.incrementGrade();
		std::cout << trial << std::endl;
		trial.decrementGrade();
		std::cout << trial << std::endl;
		test.signForm(f);
		test.decrementGrade();
		test.decrementGrade();
		f.checkExecutability(test);
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << DEFAULT << std::endl;
	}
	std::cout << std::endl;
	// try
	// {
	// 	Form	f("EB111", 1, 0);
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << RED << e.what() << DEFAULT << std::endl;
	// }
	// std::cout << std::endl;


	// try
	// {
	// 	Form	f("EB112", 1, 151);
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << RED << e.what() << DEFAULT << std::endl;
	// }
	// std::cout << std::endl;


	// try
	// {
	// 	Form	f("EB113", 151, 1);
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << RED << e.what() << DEFAULT << std::endl;
	// }
	// std::cout << std::endl;


	// try
	// {
	// 	Bureaucrat	john = Bureaucrat("John", 1);
	// 	Form		f("EB114", 150, 150);

	// 	std::cout << f << std::endl;
	// 	john.signForm(f);
	// 	std::cout << f << std::endl;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << RED << e.what() << DEFAULT << std::endl;
	// }
	// std::cout << std::endl;
	// try
	// {
	// 	Bureaucrat	joe = Bureaucrat("Joe", 10);
	// 	Form		f("EB115", 1, 1);

	// 	std::cout << f << std::endl;
	// 	joe.signForm(f);
	// 	std::cout << f << std::endl;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << RED << e.what() << DEFAULT << std::endl;
	// }
	// try
	// {
	// 	Bureaucrat	joe = Bureaucrat("Joe", 149);
	// 	Form		f("EB115", 1110, 150);

	// 	std::cout << f << std::endl;
	// 	joe.signForm(f);
	// 	std::cout << f << std::endl;
	// 	joe.decrementGrade();
	// 	std::cout << joe << std::endl;
	// 	joe.decrementGrade();
	// 	std::cout << joe << std::endl;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << RED << e.what() << DEFAULT << std::endl;
	// }
	return 0;
}