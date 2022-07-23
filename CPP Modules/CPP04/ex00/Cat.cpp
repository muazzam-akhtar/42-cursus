/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:03:38 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/17 14:14:44 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << "Default Cat Constructor called" << std::endl;
}

Cat::Cat(const Cat &other)
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	*this = other;
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &other)
{
	std::cout << "Cat Assignement operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << RED << "Meow" << DEFAULT << std::endl;
}