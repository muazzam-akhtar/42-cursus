/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HarlClass.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:10:45 by makhtar           #+#    #+#             */
/*   Updated: 2022/06/08 18:14:14 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

Harl::Harl(void) { return ;}

Harl::~Harl(void) { return ;}

void	Harl::complain(std::string level)
{
	void	(Harl::*ptr[5])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::debug};
	std::string	levels[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "DEBUG"};

	for (int i = 0; i < 5; i++)
	{
		if (levels[i] == level)
		{
			(this->*ptr[i])();
			break;
		}
	}
}

void	Harl::debug(void)
{
	std::cout << GREEN << "DEBUG\t" << DEFAULT << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << BLUE << "INFO\t" << DEFAULT << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << YELLOW << "WARNING\t" << DEFAULT << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << RED << "ERROR\t" << DEFAULT << "This is unacceptable! I want to speak to the manager now." << std::endl;
}