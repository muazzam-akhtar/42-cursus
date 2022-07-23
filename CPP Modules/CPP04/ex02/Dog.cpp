/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:09:43 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/17 14:42:23 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	this->brains = new Brain();
	std::cout << "Default Dog Constructor called" << std::endl;
}

Dog::Dog(const Dog &other)
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	*this = other;
}

Dog::~Dog(void)
{
	delete this->brains;
	std::cout << "Dog Destructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &other)
{
	std::cout << "Dog Assignement operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		this->brains = new Brain (*other.brains);
	}
	return (*this);
}

Brain	*Dog::getBrains(void) { return (this->brains); }

void	Dog::makeSound(void) const
{
	std::cout << BLUE << "Woof" << DEFAULT << std::endl;
}
