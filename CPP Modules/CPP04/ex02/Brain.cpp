/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:35:26 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/17 14:40:41 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) { std::cout << "Brain Constructor called" << std::endl; }

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

void	Brain::setIdeas(std::string idea)
{
	static int i;
	if (i == 100)
		i = 0;
	if (i >= 0 && i < 100)
		this->ideas[i++] = idea;
}

Brain::~Brain(void) { std::cout << "Brain Destructor called" << std::endl; }
