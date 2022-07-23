/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:34:14 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/20 10:14:42 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) { std::cout << "Brain Default Constructor called" << std::endl; }

Brain::Brain(const Brain &other)
{
	std::cout << "Brain Copy Constructor called" << std::endl;
	*this = other;
}

Brain	&Brain::operator=(const Brain &other)
{
	std::cout << "Brain Assignement operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100 ; i++)
			this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

void	Brain::set_ideas(const std::string idea)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = idea;
}

Brain::~Brain(void) { std::cout << "Brain Destructor called" << std::endl; }
