/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:06:58 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/08 13:06:58 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void):name("")
{
}

Zombie::~Zombie(void)
{
	Zombie::prefix();
	std::cout << "Time to die" << std::endl;
}

void	Zombie::announce(void)
{
	Zombie::prefix();
	std::cout << "Braaaaaiiiiiiinnnnssss......." << std::endl;
}

void	Zombie::prefix(void)
{
	std::cout << this->name << " ";
}

bool	Zombie::setName(std::string newName)
{
	if (newName == "")
		return (false);
	this->name = newName;
	return (true);
}