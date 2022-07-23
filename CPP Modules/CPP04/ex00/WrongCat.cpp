/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:51:40 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/15 12:56:09 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->type = "WrongCat";
	std::cout << "Default WrongCat Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
{
	std::cout << "WrongCat Copy Constructor called" << std::endl;
	*this = other;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &other)
{
	std::cout << "Cat Assignement operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Non Meow :P" << std::endl;
}