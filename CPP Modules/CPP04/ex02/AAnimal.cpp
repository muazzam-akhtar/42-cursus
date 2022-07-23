/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:02:21 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/16 10:51:09 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) :type("")
{
	std::cout << "Animal: Default Constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	std::cout << "Animal Copy Constructor called" << std::endl;
	*this = other;
}

AAnimal::AAnimal(const std::string type) : type(type) { std::cout << "Animal Constructor called with string" << std::endl; }

AAnimal	&AAnimal::operator=(const AAnimal &other)
{
	std::cout << "Animal Assignement operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << "Animal: Destructor called" << std::endl;
}

const std::string	AAnimal::getType(void) const
{
	return (this->type);
}

void	AAnimal::makeSound(void) const
{
	std::cout << "Any Animal Sound" << std::endl;
}