/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 02:14:22 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/21 11:17:15 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat	v("Bureau", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat	v("Bureau", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat	file("Muazzam", 147);
		std::cout << file;
		file.decrementGrade();
		std::cout << file;
		file.decrementGrade();
		std::cout << file;
		file.decrementGrade();
		std::cout << file;
		file.decrementGrade();
		std::cout << file;
		/* code */
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << '\n';
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat	file("Muazzam", 3);
		Bureaucrat	assign = file;
		std::cout << assign;
		file.decrementGrade();
		std::cout << assign;
		file.decrementGrade();
		std::cout << assign;
		file.decrementGrade();
		std::cout << assign;
		file.decrementGrade();
		std::cout << assign;
		/* code */
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << '\n';
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat	file("Muazzam", 3);
		Bureaucrat	assign(file);
		std::cout << assign;
		assign.incrementGrade();
		std::cout << assign;
		assign.incrementGrade();
		std::cout << assign;
		assign.incrementGrade();
		std::cout << assign;
		assign.incrementGrade();
		std::cout << assign;
		/* code */
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << '\n';
	}
	return (0);
}