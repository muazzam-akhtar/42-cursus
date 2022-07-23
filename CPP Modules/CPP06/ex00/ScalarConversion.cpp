/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 08:51:21 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/24 16:50:33 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConversion.hpp"

ScalarConversion::ScalarConversion( void )
{}

ScalarConversion::ScalarConversion( const ScalarConversion &src )
{
	*this = src;
}

ScalarConversion	&ScalarConversion::operator=(const ScalarConversion &src)
{
	(void)src;
	return (*this);
}
ScalarConversion::~ScalarConversion(void) {}

char	ScalarConversion::convertChar(double res)
{
	char	a;
	if (std::isnan(res) == true)
	{
		throw(ScalarConversion::Impossible());
	}
	a = static_cast<char>(res);
	if (std::isprint(a) == false)
	{
		throw(ScalarConversion::NonDisplayable());
	}
	return (a);
}

int	ScalarConversion::convertInt(double res)
{
	int	check;
	if (std::isnan(res) == true)
	{
		throw(ScalarConversion::Impossible());
	}
	check = static_cast<int>(res);
	return (check);
}

double	ScalarConversion::convertDouble(double res)
{
	double	check;
	check = static_cast<double>(res);
	return (check);
}

ScalarConversion::Impossible::Impossible(void) {}

ScalarConversion::Impossible::Impossible(const Impossible &src)
{
	*this = src;
}

ScalarConversion::Impossible &ScalarConversion::Impossible::operator=(const Impossible &src)
{
	(void)src;
	return(*this);
}

ScalarConversion::Impossible::~Impossible(void) throw() {}

const char	*ScalarConversion::Impossible::what(void) const throw()
{
	return ("impossible");
}

ScalarConversion::NonDisplayable::NonDisplayable(void) {}

ScalarConversion::NonDisplayable::NonDisplayable(const NonDisplayable &src)
{
	*this = src;
}

ScalarConversion::NonDisplayable &ScalarConversion::NonDisplayable::operator=(const NonDisplayable &src)
{
	(void)src;
	return(*this);
}

ScalarConversion::NonDisplayable::~NonDisplayable(void) throw() {}

const char	*ScalarConversion::NonDisplayable::what(void) const throw()
{
	return ("Non Displayable\'");
}