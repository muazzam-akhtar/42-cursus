/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:02:21 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/16 18:00:56 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) :type("")
{
	std::cout << "Animal: Default Constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal Copy Constructor called" << std::endl;
	*this = other;
}
// type(type.empty() ? "UNKNOWN" : type)
Animal::Animal(const std::string type) : type(type) { 
	std::cout << "Animal Constructor called with string" << std::endl; 
}

Animal	&Animal::operator=(const Animal &other)
{
	std::cout << "Animal Assignement operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal: Destructor called" << std::endl;
}

const std::string	Animal::getType(void) const
{
	return (this->type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Any Animal Sound" << std::endl;
}