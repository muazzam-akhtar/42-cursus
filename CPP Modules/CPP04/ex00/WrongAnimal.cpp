/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:47:15 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/15 12:56:30 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("") { std::cout << "WrongAnimal Default Constructor called" << std::endl; }

WrongAnimal::~WrongAnimal(void) { std::cout << "WrongAnimal Destructor called" << std::endl; }

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "WrongAnimal Copy Constructor called" << std::endl;
	*this = other;
}

WrongAnimal::WrongAnimal(const std::string type) : type(type) { std::cout << "WrongAnimal Constructor called with string" << std::endl; }

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal Assignement operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

const std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Any WrongAnimal Sound" << std::endl;
}