/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:56:15 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/24 16:56:17 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConversion.hpp"
# include <cctype>

void ScalarConversion::checkChar(ScalarConversion convert, double res)
{
	try
	{
		std::cout << "char: ";
		std::cout << "'" << convert.convertChar(res) << "'" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void ScalarConversion::checkInt(ScalarConversion convert, double res)
{
	try
	{
		std::cout << "int: ";
		std::cout << convert.convertInt(res) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void ScalarConversion::checkDouble(ScalarConversion convert, double res, int precision)
{
	try
	{
		std::cout << "double: ";
		std::cout << std::setprecision(precision) \
		<< std::fixed << convert.convertDouble(res) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void ScalarConversion::checkFloat(ScalarConversion convert, double res, int precision)
{
	try
	{
		std::cout << "float: ";
		std::cout << std::setprecision(precision) \
		<< std::fixed << convert.convertDouble(res) << 'f' << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}