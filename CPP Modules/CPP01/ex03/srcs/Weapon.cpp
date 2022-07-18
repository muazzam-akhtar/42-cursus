/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:09:28 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/08 14:10:22 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string type):type(type)
{
}

Weapon::~Weapon(void)
{
}

const std::string	&Weapon::getType(void)const
{
	return(this->type);
}

bool	Weapon::setType(const std::string &new_Type)
{
	if (new_Type == "")
	{
		std::cout << "new type can't be empty string" << std::endl;
		return (false);
	}
	this->type = new_Type;
	return (true);
}