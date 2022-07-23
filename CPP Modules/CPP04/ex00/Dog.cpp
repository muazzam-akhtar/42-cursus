/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:09:43 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/17 14:14:59 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << "Default Dog Constructor called" << std::endl;
}

Dog::Dog(const Dog &other)
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	*this = other;
}

Dog::~Dog(void)
{
	std::cout << "Dog Destructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &other)
{
	std::cout << "Dog Assignement operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << BLUE << "Woof" << DEFAULT << std::endl;
}
