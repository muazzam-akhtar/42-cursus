/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:06:29 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/08 17:17:20 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name):name(name)
{
}

Zombie::~Zombie(void)
{
	Zombie::prefix();
	std::cout << "Time to Die!" << std::endl;
}

void	Zombie::announce(void)
{
	Zombie::prefix();
	std::cout << "Brains...."<< std::endl;
}

void	Zombie::prefix(void)
{
	std::cout << this->name << ": ";
}

// str = ft_strdup("sdfjasdgfhagsd")
