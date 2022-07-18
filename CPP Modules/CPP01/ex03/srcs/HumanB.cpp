/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:09:23 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/08 18:22:16 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name): name(name)
{
}

HumanB::~HumanB(void)
{
}

void	HumanB::attack(void) const
{
	if (this->weapon)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " can't attack because they don't have a weapon" << std::endl;
}

bool	HumanB::setWeapon(Weapon &newWeapon)
{
	if (newWeapon.getType() == "")
	{
		std::cout << "New Weapon can't be nothing" << std::endl;
		return (false);
	}
	this->weapon = &newWeapon;
	return (true);
}
